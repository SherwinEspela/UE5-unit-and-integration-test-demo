// // Copyright 2024 Sherwin Espela. All rights reserved..


#include "Tests/ScoreWidgetModelTest.h"
#include "WidgetModels/ScoreWidgetModel.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FScoreWidgetGetFullPlayerNameTest, "ScoreWidgetModel.Get Full Player Name",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FScoreWidgetGetFullPlayerNameTest::RunTest(const FString& Parameters)
{
	ScoreWidgetModel ScoreWidget;
	ScoreWidget.SetPlayerFirstName(TEXT("Shiro"));
	ScoreWidget.SetPlayerLastName(TEXT("Amada"));
	FString FullName = ScoreWidget.GetFullPlayerName();
	FString ExpectedFullName = TEXT("Shiro Amada");
	TestEqual(TEXT("Expected full name should be Shiro Amada"), FullName, ExpectedFullName);
	return true;
}