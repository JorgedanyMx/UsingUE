
#include "ReadWriteFilev1.h"

#include "HAL/PlatformFileManager.h" //Core 

FString ReadStringFromFile(FString FilePath, bool& bOutSuccess, FString& OutInfoMessage) {
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath)) {
		bOutSuccess = false;
		OutInfoMessage = FString::Printf("Read String from File Failed - File doesn't exist - '%s' ",*FilePath);
		return "";
	}

	FString RetString = "";
	if (!FFileHelper::LoadFileToString(RetString, *FilePath)) {
		bOutSuccess = false;
		OutInfoMessage = FString::Printf("Read String from File Failed - Was not able to read file. Is this a text file - '%s' ", *FilePath);
		return "";
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf("Read String To File Success - '%s' ", *FilePath);
	return RetString;
}

FString WriteStringFromFile(FString FilePath, FString String,bool& bOutSuccess, FString& OutInfoMessage) {
	if (!FFileHelper::SaveStringToFile(String,*FilePath)) {
		bOutSuccess = false;
		OutInfoMessage = FString::Printf("Write String To File Failed - Was not able to write to file. Is your file read only? Is the path valid? - '%s' ", *FilePath);
		return;
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf("Write String To File Success - '%s' ", *FilePath);
}