#pragma once


namespace Alchemy
{

class Engine
{
public:
    Engine();

    ~Engine();

    void Init();

    void Loop(float dt);

    void Cleanup();
};


} // namespace Alchemy