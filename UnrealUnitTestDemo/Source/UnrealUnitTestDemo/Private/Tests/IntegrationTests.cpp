// // Copyright 2024 Sherwin Espela. All rights reserved..


#include "Tests/IntegrationTests.h"
#include "WidgetModels/ScoreWidgetModel.h"
#include "Managers/ScoreManager.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FIntegrationGetTotalScoreTest, "IntegrationTests.ScoreManagerAndScoreWidgetModel.Get Score",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FIntegrationGetTotalScoreTest::RunTest(const FString& Parameters)
{
	ScoreWidgetModel* ScoreWidget = new ScoreWidgetModel();
	ScoreManager* SM = new ScoreManager();

	ScoreWidget->SetScoreManager(SM);
	SM->AddScore(25); // 25
	SM->RemoveScore(5); // 25 - 5 = 20
	SM->AddScore(30); // 20 + 30 = 50
	SM->RemoveScore(10); // 50 - 10 = 40
	SM->RemoveScore(20); // 40 - 20 = 20
	SM->AddScore(80); // 20 + 80 = 100

	FString ExpectedTotalScore = FString::Printf(TEXT("Total Score: %i"), 100);
	TestEqual(TEXT("Expected Total Score should be 100 points"), ScoreWidget->GetTotalScore(), ExpectedTotalScore);
	
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FIntegrationGetStarsTest, "IntegrationTests.ScoreManagerAndScoreWidgetModel.Get Stars",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FIntegrationGetStarsTest::RunTest(const FString& Parameters)
{
	ScoreWidgetModel* ScoreWidget = new ScoreWidgetModel();
	ScoreManager* SM = new ScoreManager();

	ScoreWidget->SetScoreManager(SM);
	SM->AddScore(25); // 25
	SM->RemoveScore(5); // 25 - 5 = 20
	SM->AddScore(30); // 20 + 30 = 50
	SM->RemoveScore(10); // 50 - 10 = 40
	SM->RemoveScore(20); // 40 - 20 = 20
	SM->AddScore(80); // 20 + 80 = 100

	FString ExpectedTotalStars = FString::Printf(TEXT("Total Stars: 3"));
	TestEqual(TEXT("Expected Total Stars should be 3"), ScoreWidget->GetStars(), ExpectedTotalStars);

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FIntegrationGetRewardsTest, "IntegrationTests.ScoreManagerAndScoreWidgetModel.Get Reward Points",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FIntegrationGetRewardsTest::RunTest(const FString& Parameters)
{
	ScoreWidgetModel* ScoreWidget = new ScoreWidgetModel();
	ScoreManager* SM = new ScoreManager();

	ScoreWidget->SetScoreManager(SM);
	SM->AddScore(25); // 25
	SM->RemoveScore(5); // 25 - 5 = 20
	SM->AddScore(30); // 20 + 30 = 50
	SM->RemoveScore(10); // 50 - 10 = 40
	SM->RemoveScore(20); // 40 - 20 = 20
	SM->AddScore(80); // 20 + 80 = 100

	FString ExpectedTotalStars = FString::Printf(TEXT("Total Stars: 3"));
	TestEqual(TEXT("Expected Total Stars should be 3"), ScoreWidget->GetStars(), ExpectedTotalStars);

	FString ExpectedRewardPoints = FString::Printf(TEXT("Total Reward Points: 30"));
	TestEqual(TEXT("Expected to have 20 reward points"), ScoreWidget->GetRewardPoints(), ExpectedRewardPoints);

	return true;
}
