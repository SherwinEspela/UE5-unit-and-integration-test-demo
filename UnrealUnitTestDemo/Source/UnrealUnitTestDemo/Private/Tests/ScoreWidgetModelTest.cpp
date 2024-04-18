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

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FScoreWidgetPlayerRankTest, "ScoreWidgetModel.Get Player Rank",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FScoreWidgetPlayerRankTest::RunTest(const FString& Parameters)
{
	ScoreWidgetModel ScoreWidget;
	ScoreWidget.SetPlayerRank(2);
	FString Rank = ScoreWidget.GetPlayerRank();
	FString ExpectedRank = "2";
	TestEqual(TEXT("Expected rank should be 2"), Rank, ExpectedRank);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FScoreWidgetGetLevelTest, "ScoreWidgetModel.Get Level",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FScoreWidgetGetLevelTest::RunTest(const FString& Parameters)
{
	ScoreWidgetModel ScoreWidget;
	ScoreWidget.SetLevel(3);
	FString Level = ScoreWidget.GetLevel();
	FString ExpectedLevel = "3";
	TestTrue(TEXT("Should contain a the word level"), Level.ToLower().Contains("level"));
	TestEqual(TEXT("Expected rank should be 3"), Level, ExpectedLevel);
	return true;
}