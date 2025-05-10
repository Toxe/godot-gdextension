#pragma once

#include "godot_cpp/classes/sprite2d.hpp"

class GDExample : public godot::Sprite2D {
    GDCLASS(GDExample, Sprite2D)

private:
    double time_passed;

protected:
    static void _bind_methods();

public:
    GDExample();
    ~GDExample();

    void _process(double delta) override;
};
