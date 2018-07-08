// Fill out your copyright notice in the Description page of Project Settings.

#include "InGameMenu.h"
#include "Components/Button.h"

bool UInGameMenu::Initialize()
{
	bool Success = Super:: Initialize();
	if (!Success) return false;
	
	if (!ensure(InGameCancelButton != nullptr)) return false;
	InGameCancelButton->OnClicked.AddDynamic(this, &UInGameMenu::InGameCancelPressed);

	if (!ensure(InGameQuitButton != nullptr)) return false;
	InGameQuitButton->OnClicked.AddDynamic(this, &UInGameMenu::InGameQuitPressed);
	
	return true;
}

void UInGameMenu::InGameCancelPressed()
{
	Teardown();
}

void UInGameMenu::InGameQuitPressed()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->LoadMainMenu();
	}
}
