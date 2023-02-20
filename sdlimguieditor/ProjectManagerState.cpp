#include "ProjectManagerState.h"
#include "IconsFontAwesome4.h" //header with names for every icon.
#include "dearimgui/imgui.h"
#include "dearimgui/imgui_impl_sdl.h"
#include "dearimgui/imgui_impl_sdlrenderer.h"
#include "dearimgui/imgui_stdlib.h"  //for using std::string in some imgui funcions.
#include "editor.h"

const std::string ProjectManagerState::s_ID = "PROJECTMANAGER";

ProjectManagerState::ProjectManagerState()
{
}


ProjectManagerState::~ProjectManagerState()
{
}

void ProjectManagerState::update()
{
}

void ProjectManagerState::render()
{
	ImGui::SetNextItemOpen(true, 0);
	ImGui::Begin("Project Manager");
		static char str0[128] = "";
		ImGui::InputText("Project name", str0, IM_ARRAYSIZE(str0));
		if (ImGui::Button("Create Project"))
		{
			if (strlen(str0) > 0)
			{
				Editor::Instance()->project = new Entity(str0, "project", str0);
				Editor::Instance()->getStateMachine()->changeState(EDITOR);
			}
		}
		if (ImGui::Button("Return To Editor"))
		{
			if(Editor::Instance()->project != nullptr) Editor::Instance()->getStateMachine()->changeState(EDITOR);
		}
	ImGui::End();

	ImGui::ShowDemoWindow();
}

bool ProjectManagerState::onEnter()
{
	return false;
}

bool ProjectManagerState::onExit()
{
	return false;
}
