/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Splash.h
Project: CS230
Author: Kevin Wright
Creation date: 2/10/2021
-----------------------------------------------------------------*/
#pragma once
#include<glfw/glfw3.h>
#include <core.h>
#include<Logger.h>
#include <GameState.h>
namespace HookBill
{
	class Splash : public GameState
	{
	public:
		Splash();
		virtual void Load() override;
		virtual void Update() override;
		virtual void Draw()  override;
		virtual void ImGuiDraw() override;
		virtual void Unload() override;

		std::string GetName() override { return "Splash"; }

	private:
	};
}