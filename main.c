#include "raylib.h"
#include <stdbool.h>

// --- Constants ---
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAX_ENEMIES 10

// --- Enemy Structure ---
typedef struct Enemy {
    Vector2 position;
    float speed;
    bool active;
} Enemy;

// --- EnemyManager Structure ---
typedef struct EnemyManager {
    Enemy enemies[MAX_ENEMIES];
} EnemyManager;

// --- EnemyManager Functions ---
void InitEnemyManager(EnemyManager* manager) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        manager->enemies[i].position = (Vector2){ -100, -100 };
        manager->enemies[i].speed = 50;
        manager->enemies[i].active = false;
    }
}

void EnemyManager_SpawnEnemy(EnemyManager* manager) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (!manager->enemies[i].active) {
            manager->enemies[i].position = (Vector2){ 0, GetRandomValue(100, SCREEN_HEIGHT - 100) };
            manager->enemies[i].active = true;
            break;
        }
    }
}

void EnemyManager_UpdateEnemies(EnemyManager* manager, float delta) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (manager->enemies[i].active) {
            manager->enemies[i].position.x += manager->enemies[i].speed * delta;
            if (manager->enemies[i].position.x > SCREEN_WIDTH) {
                manager->enemies[i].active = false;
            }
        }
    }
}

void EnemyManager_DrawEnemies(EnemyManager* manager) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (manager->enemies[i].active) {
            DrawCircleV(manager->enemies[i].position, 10, RED);
        }
    }
}

// --- Main Function ---
int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tower Defense - Refactored Example");
    SetTargetFPS(60);

    EnemyManager gameEnemyManager;
    InitEnemyManager(&gameEnemyManager);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        if (IsKeyPressed(KEY_SPACE)) {
            EnemyManager_SpawnEnemy(&gameEnemyManager);
        }

        EnemyManager_UpdateEnemies(&gameEnemyManager, dt);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Press SPACE to spawn enemies", 10, 10, 20, DARKGRAY);
        EnemyManager_DrawEnemies(&gameEnemyManager);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
