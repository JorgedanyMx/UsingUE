// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "kismet/BlueprintFunctionLibrary.h"
#include "ReadWriteFilev1.generated.h"

UCLASS()
class U_ReadWriteFilev1 : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "JD|ReadWriteFile")
	static FString ReadStringFromFile(FString FilePath, bool& bOutSuccess, FString& OutInfoMessage); 

	UFUNCTION(BlueprintCallable, Category = "JD|ReadWriteFile")
	static FString WriteStringFromFile(FString FilePath, bool& bOutSuccess, FString& OutInfoMessage);
};