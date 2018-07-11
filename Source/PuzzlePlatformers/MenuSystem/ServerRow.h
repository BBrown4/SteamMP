// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ServerRow.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMERS_API UServerRow : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ServerName;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* HostUsername;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ConnectionFraction;
	
	UPROPERTY(BlueprintReadOnly)
	bool Selected = false;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* RowButton;

	void Setup(class UMainMenu* Parent, uint32 Index);

private:
	UPROPERTY()
	class UMainMenu* Parent;

	uint32 Index;

	UFUNCTION()
	void OnClicked();
	
};
