#include <iostream>
#include <vector>

class HitBox {
    double x, y, width,height; 
};

class Entity {
protected:
    double x, y, z;
    HitBox hitbox;
public:
    virtual void update() = 0;
    virtual void render() = 0;
};

class Player : public Entity {
    double hitpoints = 100;
public:
    void damage(double hp) {
        hitpoints -= hp;
    }

    void update() override {
        std::cout << "Player Updated" << "\n";
    }
    void render() override {
        std::cout << "Player rendered" << "\n";
    }
};

class Tree : public Entity {
public:
    void update() override {
        std::cout << "Tree Updated" << "\n";
    }
    void render() override {
        std::cout << "Tree rendered" << "\n";
    }
};

class Projectile : public Entity {
public:
    void update() override {
        std::cout << "Projectile Updated" << "\n";
    }
    void render() override {
        std::cout << "Projectile rendered" << "\n";
    }
};

int main() {
    Player p;
    Tree t;
    Projectile proj;

    std::vector<Entity*> entities {&p, &t, &proj};

    while (true) {
        for (auto& entity: entities) {
            entity->render();
            entity->update();
        }
    }

    return 0;
}