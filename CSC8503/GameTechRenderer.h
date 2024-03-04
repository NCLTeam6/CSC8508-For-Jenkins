#pragma once
#include "OGLRenderer.h"
#include "OGLShader.h"
#include "OGLTexture.h"
#include "OGLMesh.h"
#include "GameWorld.h"

namespace NCL {
	class Maths::Vector3;
	class Maths::Vector4;
	namespace CSC8503 {
		class RenderObject;

		class GameTechRenderer : public OGLRenderer	{
		public:

			struct UIen {
				NCL::Rendering::OGLMesh* mesh;
				int width=512;
				int height=512;
				int channels=4;
				int flags=0;
				char* texture;
				std::string tag;
			};

			GameTechRenderer(GameWorld& world);
			~GameTechRenderer();

			Mesh*		LoadMesh(const std::string& name);
			Texture*	LoadTexture(const std::string& name);
			Shader*		LoadShader(const std::string& vertex, const std::string& fragment);
			void        Loadhealth();
			static void CreateGameUI(std::vector<NCL::Maths::Vector3> UIpox, const std::string& name, std::string type);

			static const std::vector<UIen>& GetUIEntries();

			static void UpdateUI();
			static void deletUI(int i);

		protected:
			std::unordered_map<std::string, SharedOGLTexture> textureCache;

		protected:
			void NewRenderLines();
			void NewRenderText();

			void Newbloodline();

			void RenderFrame()	override;

			OGLShader*		defaultShader;

			GameWorld&	gameWorld;

			void BuildObjectList();
			void SortObjectList();
			void RenderShadowMap();
			void RenderCamera(); 
			void RenderSkybox();
	

			void LoadSkybox();
			void Loadhealth(GameUI ui);

			void SetDebugStringBufferSizes(size_t newVertCount);
			void SetDebugLineBufferSizes(size_t newVertCount);
			void SetDebugBLineBufferSizes(size_t newVertCount);

			vector<const RenderObject*> activeObjects;

			OGLShader*  debugShader;
			OGLShader* healthShader;
			OGLShader*  skyboxShader;
			OGLMesh*	skyboxMesh;
			GLuint		skyboxTex;

			//OGLShader* healthShader;
			//OGLMesh*   healthMesh;
			//GLuint		healthTex;

			//shadow mapping things
			OGLShader*	shadowShader;
			GLuint		shadowTex;
			GLuint		shadowFBO;
			Matrix4     shadowMatrix;

			Vector4		lightColour;
			float		lightRadius;
			Vector3		lightPosition;

			//Debug data storage things
			vector<Vector3> debugLineData;
			vector<Vector3> debugBLineData;
			vector<Vector3> debugTextPos;
			vector<Vector4> debugTextColours;
			vector<Vector2> debugTextUVs;

			GLuint lineVAO;
			GLuint lineVertVBO;
			size_t lineCount;
			 
			GLuint textVAO;
			GLuint textVertVBO;
			GLuint textColourVBO;
			GLuint textTexVBO;
			size_t textCount;


			static std::vector<UIen>	UIEntries;
			GLuint texture;

		};
	}
}

 