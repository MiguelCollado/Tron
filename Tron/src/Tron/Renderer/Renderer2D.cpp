#include "tnpch.h"
#include "Tron/Renderer/Renderer2D.h"

#include "Tron/Renderer/VertexArray.h"
#include "Tron/Renderer/Shader.h"
#include "Tron/Renderer/RenderCommand.h"

#include <glm/ext/matrix_transform.hpp>

namespace Tron {

    struct QuadVertex {
        glm::vec3 Position;
        glm::vec4 Color;
        glm::vec2 TexCoord;
        float TexIndex;
        float TilingFactor;
    };

    struct Renderer2DData {
        // Max limiters for each Draw call
        static const uint32_t MaxQuads = 10000;
        static const uint32_t MaxVertices = MaxQuads * 4;
        static const uint32_t MaxIndices = MaxQuads * 6;
        static const uint32_t MaxTextureSlots = 32; // TODO: RenderCaps

        Ref<VertexArray> QuadVertexArray;
        Ref<VertexBuffer> QuadVertexBuffer;
        Ref<Shader> TextureShader;
        Ref<Texture2D> WhiteTexture;

        // Ref parameters
        uint32_t QuadIndexCount = 0;
        QuadVertex* QuadVertexBufferBase = nullptr;
        QuadVertex* QuadVertexBufferPointer = nullptr;

        std::array<Ref<Texture2D>, MaxTextureSlots> TextureSlots;
        uint32_t TextureSlotIndex = 1; // 0 -> white texture;

        glm::vec4 QuadVertexPositions[4]{};

        Renderer2D::Statistics Stats;
    };

    static Renderer2DData s_Data;

    void Renderer2D::Init() {
        TN_PROFILE_FUNCTION();

        s_Data.QuadVertexArray = VertexArray::Create();

        // Vertex Buffer
        s_Data.QuadVertexBuffer = VertexBuffer::Create(Tron::Renderer2DData::MaxVertices * sizeof(QuadVertex));
        s_Data.QuadVertexBuffer->SetLayout({
            { ShaderDataType::Float3, "a_Position"},
            { ShaderDataType::Float4, "a_Color"},
            { ShaderDataType::Float2, "a_TexCoord"},
            { ShaderDataType::Float, "a_TexIndex"},
            { ShaderDataType::Float, "a_TilingFactor"},
        });
        s_Data.QuadVertexArray->AddVertexBuffer(s_Data.QuadVertexBuffer);

        s_Data.QuadVertexBufferBase = new QuadVertex[Tron::Renderer2DData::MaxVertices];

        // Index Buffer
        auto* quadIndices = new uint32_t[Tron::Renderer2DData::MaxIndices];

        uint32_t offset = 0;
        for (uint32_t i = 0; i < Tron::Renderer2DData::MaxIndices; i += 6) {
            quadIndices[i + 0] = offset + 0;
            quadIndices[i + 1] = offset + 1;
            quadIndices[i + 2] = offset + 2;

            quadIndices[i + 3] = offset + 2;
            quadIndices[i + 4] = offset + 3;
            quadIndices[i + 5] = offset + 0;

            offset += 4;
        }

        Ref<IndexBuffer> quadIB = IndexBuffer::Create(quadIndices, Tron::Renderer2DData::MaxIndices);
        s_Data.QuadVertexArray->SetIndexBuffer(quadIB);
        delete[] quadIndices;

        s_Data.WhiteTexture = Texture2D::Create(1, 1);
        uint32_t whiteTextureData = 0xFFFFFFFF;
        s_Data.WhiteTexture->SetData(&whiteTextureData, sizeof(uint32_t));


        int32_t samplers[Tron::Renderer2DData::MaxTextureSlots];
        for (uint32_t i = 0; i < Tron::Renderer2DData::MaxTextureSlots; i++) {
            samplers[i] = i;
        }

        s_Data.TextureShader = Shader::Create("assets/shaders/Texture.glsl");
        s_Data.TextureShader->Bind();
        s_Data.TextureShader->SetIntArray("u_Textures", samplers, Tron::Renderer2DData::MaxTextureSlots);

        // Set all texture slots to 0
        s_Data.TextureSlots[0] = s_Data.WhiteTexture;

        s_Data.QuadVertexPositions[0] = { -0.5f, -0.5f, 0.0f, 1.0f};
        s_Data.QuadVertexPositions[1] = {  0.5f, -0.5f, 0.0f, 1.0f};
        s_Data.QuadVertexPositions[2] = {  0.5f,  0.5f, 0.0f, 1.0f};
        s_Data.QuadVertexPositions[3] = { -0.5f,  0.5f, 0.0f, 1.0f};
    }

    void Renderer2D::Shutdown() {
        TN_PROFILE_FUNCTION();

        delete[] s_Data.QuadVertexBufferBase;
    }

    void Renderer2D::BeginScene(const OrthographicCamera &camera) {
        TN_PROFILE_FUNCTION();

        s_Data.TextureShader->Bind();
        s_Data.TextureShader->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());

        s_Data.QuadIndexCount = 0;
        s_Data.QuadVertexBufferPointer = s_Data.QuadVertexBufferBase;

        s_Data.TextureSlotIndex = 1;
    }

    void Renderer2D::EndScene() {
        TN_PROFILE_FUNCTION();

        //Casteamos a uint8_t porque necesitamos saber el número de elementos en formato byte
        auto dataSize = (uint32_t)((uint8_t*)s_Data.QuadVertexBufferPointer - (uint8_t*)s_Data.QuadVertexBufferBase);
        s_Data.QuadVertexBuffer->SetData(s_Data.QuadVertexBufferBase, dataSize);

        Flush();
    }

    void Renderer2D::Flush() {
        if (s_Data.QuadIndexCount == 0)
            return;

        // Bind Textures
        for (uint32_t i = 0; i < s_Data.TextureSlotIndex; i++) {
            s_Data.TextureSlots[i]->Bind(i);
        }

        RenderCommand::DrawIndexed(s_Data.QuadVertexArray, s_Data.QuadIndexCount);
        s_Data.Stats.DrawCalls++;
    }

    void Renderer2D::FlushAndReset() {
        EndScene();

        s_Data.QuadIndexCount = 0;
        s_Data.QuadVertexBufferPointer = s_Data.QuadVertexBufferBase;

        s_Data.TextureSlotIndex = 1;
    }

    void Renderer2D::DrawQuad(const glm::vec2 &position, const glm::vec2 &size, const glm::vec4 &color) {
        DrawQuad({position.x, position.y, 0.0f}, size, color);
    }

    void Renderer2D::DrawQuad(const glm::vec3 &position, const glm::vec2 &size, const glm::vec4 &color) {
        TN_PROFILE_FUNCTION();

        constexpr size_t quadVertexCount = 4;
        const float texIndex = 0.0f; // White Texture
        constexpr glm::vec2 textureCoords[] = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };
        const float tilingFactor = 1.0f;

        if (s_Data.QuadIndexCount >= Tron::Renderer2DData::MaxIndices) {
            FlushAndReset();
        }

        glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
              * glm::scale(glm::mat4(1.0f), {size.x, size.y, 1.0f});

        for (size_t i = 0; i < quadVertexCount; i++) {
            s_Data.QuadVertexBufferPointer->Position = transform * s_Data.QuadVertexPositions[i];
            s_Data.QuadVertexBufferPointer->Color = color;
            s_Data.QuadVertexBufferPointer->TexCoord = textureCoords[i];
            s_Data.QuadVertexBufferPointer->TexIndex = texIndex;
            s_Data.QuadVertexBufferPointer->TilingFactor = tilingFactor;
            s_Data.QuadVertexBufferPointer++;
        }

        s_Data.QuadIndexCount += 6;

        s_Data.Stats.QuadCount++;
    }

    void Renderer2D::DrawQuad(const glm::vec2 &position, const glm::vec2 &size, const Ref<Texture2D> &texture, float tilingFactor, const glm::vec4& tintColor) {
        DrawQuad({position.x, position.y, 0.0f}, size, texture, tilingFactor, tintColor);
    }

    void Renderer2D::DrawQuad(const glm::vec3 &position, const glm::vec2 &size, const Ref<Texture2D> &texture, float tilingFactor, const glm::vec4& tintColor) {
        TN_PROFILE_FUNCTION();

        constexpr size_t quadVertexCount = 4;
        constexpr glm::vec2 textureCoords[] = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };

        if (s_Data.QuadIndexCount >= Tron::Renderer2DData::MaxIndices) {
            FlushAndReset();
        }

        // Check if the texture is already in use
        float textureIndex = 0.0f;
        for (uint32_t i = 1; i < s_Data.TextureSlotIndex; i++)
        {
            if (*s_Data.TextureSlots[i].get() == *texture.get())
            {
                textureIndex = (float)i;
                break;
            }
        }

        if (textureIndex == 0.0f) {
            if (s_Data.TextureSlotIndex >= Renderer2DData::MaxTextureSlots)
				FlushAndReset();

            textureIndex = (float)s_Data.TextureSlotIndex;
            s_Data.TextureSlots[s_Data.TextureSlotIndex] = texture;
            s_Data.TextureSlotIndex++;
        }

        glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
              * glm::scale(glm::mat4(1.0f), {size.x, size.y, 1.0f});

        for (size_t i = 0; i < quadVertexCount; i++) {
            s_Data.QuadVertexBufferPointer->Position = transform * s_Data.QuadVertexPositions[i];
            s_Data.QuadVertexBufferPointer->Color = tintColor;
            s_Data.QuadVertexBufferPointer->TexCoord = textureCoords[i];
            s_Data.QuadVertexBufferPointer->TexIndex = textureIndex;
            s_Data.QuadVertexBufferPointer->TilingFactor = tilingFactor;
            s_Data.QuadVertexBufferPointer++;
        }

        s_Data.QuadIndexCount += 6;

        s_Data.Stats.QuadCount++;
    }

    void Renderer2D::DrawRotatedQuad(const glm::vec2 &position, const glm::vec2 &size, float rotation,
                                     const glm::vec4 &color) {
        DrawRotatedQuad({position.x, position.y, 0.0f}, size, rotation, color);
    }

    void Renderer2D::DrawRotatedQuad(const glm::vec3 &position, const glm::vec2 &size, float rotation,
                                     const glm::vec4 &color) {
        TN_PROFILE_FUNCTION();

        constexpr size_t quadVertexCount = 4;
        const float texIndex = 0.0f; // White Texture
        constexpr glm::vec2 textureCoords[] = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };
        const float tilingFactor = 1.0f;

        if (s_Data.QuadIndexCount >= Tron::Renderer2DData::MaxIndices) {
            FlushAndReset();
        }

        glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
              * glm::rotate(glm::mat4(1.0f), glm::radians(rotation), {0.0f, 0.0f, 1.0f})
              * glm::scale(glm::mat4(1.0f), {size.x, size.y, 1.0f});

        for (size_t i = 0; i < quadVertexCount; i++) {
            s_Data.QuadVertexBufferPointer->Position = transform * s_Data.QuadVertexPositions[i];
            s_Data.QuadVertexBufferPointer->Color = color;
            s_Data.QuadVertexBufferPointer->TexCoord = textureCoords[i];
            s_Data.QuadVertexBufferPointer->TexIndex = texIndex;
            s_Data.QuadVertexBufferPointer->TilingFactor = tilingFactor;
            s_Data.QuadVertexBufferPointer++;
        }

        s_Data.QuadIndexCount += 6;

        s_Data.Stats.QuadCount++;
    }

    void Renderer2D::DrawRotatedQuad(const glm::vec2 &position, const glm::vec2 &size, float rotation,
                                     const Ref<Texture2D> &texture, float tilingFactor, const glm::vec4& tintColor) {
        DrawRotatedQuad({position.x, position.y, 0.0f}, size, rotation, texture, tilingFactor, tintColor);
    }

    void Renderer2D::DrawRotatedQuad(const glm::vec3 &position, const glm::vec2 &size, float rotation,
                                     const Ref<Texture2D> &texture, float tilingFactor, const glm::vec4& tintColor) {
        TN_PROFILE_FUNCTION();

        constexpr size_t quadVertexCount = 4;
        constexpr glm::vec2 textureCoords[] = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };


        if (s_Data.QuadIndexCount >= Tron::Renderer2DData::MaxIndices) {
            FlushAndReset();
        }

        // Check if the texture is already in use
        float textureIndex = 0.0f;
        for (uint32_t i = 1; i < s_Data.TextureSlotIndex; i++)
        {
            if (*s_Data.TextureSlots[i].get() == *texture.get())
            {
                textureIndex = (float)i;
                break;
            }
        }

        if (textureIndex == 0.0f) {
            if (s_Data.TextureSlotIndex >= Renderer2DData::MaxTextureSlots)
                FlushAndReset();

            textureIndex = (float)s_Data.TextureSlotIndex;
            s_Data.TextureSlots[s_Data.TextureSlotIndex] = texture;
            s_Data.TextureSlotIndex++;
        }

        glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
                * glm::rotate(glm::mat4(1.0f), glm::radians(rotation), {0.0f, 0.0f, 1.0f})
                * glm::scale(glm::mat4(1.0f), {size.x, size.y, 1.0f});

        for (size_t i = 0; i < quadVertexCount; i++) {
            s_Data.QuadVertexBufferPointer->Position = transform * s_Data.QuadVertexPositions[i];
            s_Data.QuadVertexBufferPointer->Color = tintColor;
            s_Data.QuadVertexBufferPointer->TexCoord = textureCoords[i];
            s_Data.QuadVertexBufferPointer->TexIndex = textureIndex;
            s_Data.QuadVertexBufferPointer->TilingFactor = tilingFactor;
            s_Data.QuadVertexBufferPointer++;
        }

        s_Data.QuadIndexCount += 6;

        s_Data.Stats.QuadCount++;
    }

    void Renderer2D::ResetStats() {
        memset(&s_Data.Stats, 0, sizeof(Statistics));
    }

    Renderer2D::Statistics Renderer2D::GetStats() {
        return s_Data.Stats;
    }
}