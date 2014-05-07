

#pragma once

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
//#include <glm/gtc/matrix_transform.hpp>

#include "log.h"

struct KeyFrame {
    glm::vec3 position;
    glm::vec3 direction;
    glm::quat rotation;
    float time;

    KeyFrame(const glm::vec3& pos, const glm::vec3& dir, float time, const glm::quat& rot = glm::quat()):
        position(pos), direction(dir), time(time), rotation(rot) {}
};


class KeyFrameAnimation {

    std::vector<KeyFrame> keyFrames;
    unsigned currentFrame;
    float currentTime; //, transition;
    
    bool repeat, ended;
    //unsigned repeatCount;

    glm::vec3 currentPos, currentDir;
    glm::quat currentRot;

    void DoLerp(const KeyFrame& first, const KeyFrame& second, float amount);

public:
    KeyFrameAnimation(float timeOffset = 0.0f) : currentFrame(0), currentTime(0), repeat(true), ended(false)/*, repeatCount(0), transition(0)*/ {
    }

    void AddKeyFrame(const KeyFrame& keyFrame) {      
        keyFrames.push_back(keyFrame);
    }

    unsigned GetCurrentKeyFrame(unsigned lastFrame);

    float GetTransition(const KeyFrame& first, const KeyFrame& second);

    void Update(float deltaTime);

    const KeyFrame& GetKeyFrame(unsigned i) const {
        return keyFrames[i];
    }
    unsigned KeyFrameCount() const {
        return keyFrames.size();
    }

    glm::vec3& GetCurrentPosition() {
        return currentPos;
    }
    glm::vec3& GetCurrentDirection() {
        return currentDir;
    }
    glm::quat& GetCurrentRotation() {
        return currentRot;
    }
    //glm::mat4 GetCurrentMatrix() {
    //    return glm::mat4();
    //}

    bool HasEnded() {
        return ended;
    }

    void MakeOrbit(float segments, float timestep, float radius, const glm::vec3 target);
};