// Copyright 2024 Sherwin Espela. All rights reserved.

#include "Managers/ScoreManager.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FScoreManagerAddScoreTest, "ScoreManager.Add Score",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FScoreManagerAddScoreTest::RunTest(const FString& Parameters)
{
	ScoreManager* SM = new ScoreManager();
	SM->AddScore(10);
	int TotalScore = SM->GetTotalScore();
	TestEqual(TEXT("Expected to have 10 points"), TotalScore, 10);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FScoreManagerRemoveScoreTest, "ScoreManager.Remove Score",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FScoreManagerRemoveScoreTest::RunTest(const FString& Parameters)
{
	ScoreManager* SM = new ScoreManager();
	SM->AddScore(20);
	SM->RemoveScore(5);
	int TotalScore = SM->GetTotalScore();
	TestEqual(TEXT("Expected to have 15 points"), TotalScore, 15);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FScoreManagerStressTest, "ScoreManager.Stress Test",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FScoreManagerStressTest::RunTest(const FString& Parameters)
{
	ScoreManager* SM = new ScoreManager();
	SM->AddScore(25); // 25
	SM->RemoveScore(5); // 25 - 5 = 20
	SM->AddScore(30); // 20 + 30 = 50
	SM->RemoveScore(10); // 50 - 10 = 40
	SM->RemoveScore(20); // 40 - 20 = 20
	SM->AddScore(80); // 20 + 80 = 100
	int TotalScore = SM->GetTotalScore();
	TestEqual(TEXT("Expected total score should be 100 points"), TotalScore, 100);
	return true;
}
