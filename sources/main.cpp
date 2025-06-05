#include "linesegment.cpp"

int generation = 0;

void onMouseDown(std::vector<LineSegment*>& segments)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		generation++;
			std::vector<LineSegment*> nextGeneration;
			for (LineSegment* s : segments) {
				std::vector<LineSegment*> children = s->generate();
				for (LineSegment* segment : children) {
					nextGeneration.push_back(segment);
				}
			}
			segments = nextGeneration;
		}
}

int main() {
	InitWindow(0, 0, "Koch Snowflake");
	ToggleBorderlessWindowed();
	SetTargetFPS(30);

	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();
	int scaler;
	if (screenHeight > screenWidth)
		scaler = screenWidth;
	else
		scaler = screenHeight;

	std::vector<LineSegment*> segments;
	Vector2 a = { scaler *0.1f, scaler *0.3f };
	Vector2 b = { scaler *0.9f, scaler *0.3f };
	Vector2 c = { scaler *0.5f, scaler *0.9f };
	LineSegment* segment1 = new LineSegment(a, b);
	LineSegment* segment2 = new LineSegment(b, c);
	LineSegment* segment3 = new LineSegment(c, a);
	segments.push_back(segment1);
	segments.push_back(segment2);
	segments.push_back(segment3);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		onMouseDown(segments);
		DrawText(TextFormat("Generation: %d", generation), 10, 10, scaler * 0.05f, WHITE);
		DrawText("Click to generate next generation", 10, screenHeight-scaler * 0.07f, scaler * 0.03f, WHITE);
		DrawText("Press ESC to close", 10, screenHeight - scaler * 0.03f, scaler * 0.03f, WHITE);
		for (LineSegment* segment : segments) {
			segment->draw();
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}