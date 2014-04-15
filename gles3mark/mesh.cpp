

#include "mesh.h"


void Mesh::MakeTestMesh() {
    vertices = {
        // Walls
        glm::vec3(-5.0, -5.0, -5.0),
        glm::vec3(-5.0, -5.0,  5.0),
        glm::vec3( 5.0, -5.0,  5.0),
        glm::vec3( 5.0, -5.0, -5.0),
    
        glm::vec3(-5.0,  5.0, -5.0),
        glm::vec3(-5.0,  5.0,  5.0),
        glm::vec3( 5.0,  5.0,  5.0),
        glm::vec3( 5.0,  5.0, -5.0),

        glm::vec3(-5.0, -5.0, -5.0),
        glm::vec3(-5.0, -5.0,  5.0),
        glm::vec3(-5.0,  5.0,  5.0),
        glm::vec3(-5.0,  5.0, -5.0),

        glm::vec3( 5.0, -5.0, -5.0),
        glm::vec3( 5.0, -5.0,  5.0),
        glm::vec3( 5.0,  5.0,  5.0),
        glm::vec3( 5.0,  5.0, -5.0),
        // Roof
        glm::vec3(-5.0,  5.0, -5.0),
        glm::vec3( 5.0,  5.0, -5.0),
        glm::vec3( 0.0, 11.0,  0.0),

        glm::vec3( 5.0,  5.0, -5.0),
        glm::vec3( 5.0,  5.0,  5.0),
        glm::vec3( 0.0, 11.0,  0.0),

        glm::vec3( 5.0,  5.0,  5.0),
        glm::vec3(-5.0,  5.0,  5.0),
        glm::vec3( 0.0, 11.0,  0.0),

        glm::vec3(-5.0,  5.0,  5.0),
        glm::vec3(-5.0,  5.0, -5.0),
        glm::vec3( 0.0, 11.0,  0.0),
    };

    texCoords = {
        // Walls
        glm::vec2( 0.0, 0.0 ),
        glm::vec2( 0.0, 4.0 ),
        glm::vec2( 4.0, 4.0 ),
        glm::vec2( 4.0, 0.0 ),
                     
        glm::vec2( 0.0, 0.0 ),
        glm::vec2( 0.0, 2.0 ),
        glm::vec2( 2.0, 2.0 ),
        glm::vec2( 2.0, 0.0 ),
                     
        glm::vec2( 0.0, 0.0 ),
        glm::vec2( 0.0, 1.0 ),
        glm::vec2( 1.0, 1.0 ),
        glm::vec2( 1.0, 0.0 ),
                     
        glm::vec2( 0.0, 0.0 ),
        glm::vec2( 0.0, 1.0 ),
        glm::vec2( 1.0, 1.0 ),
        glm::vec2( 1.0, 0.0 ),
        // Roof
        glm::vec2( 0.0, 0.0 ),
        glm::vec2( 1.0, 0.0 ),
        glm::vec2( 0.0, 1.0 ),
                     
        glm::vec2( 0.0, 0.0 ),
        glm::vec2( 1.0, 0.0 ),
        glm::vec2( 0.0, 1.0 ),
                     
        glm::vec2( 0.0, 0.0 ),
        glm::vec2( 0.0, 1.0 ),
        glm::vec2( 1.0, 1.0 ),
                     
        glm::vec2( 0.0, 1.0 ),
        glm::vec2( 0.0, 0.0 ),
        glm::vec2( 1.0, 1.0 ),
    };    

    // House indices
    faces = {
        //Walls
        glm::ivec3( 0,  1,  2),
        glm::ivec3( 0,  2,  3),
        glm::ivec3( 4,  5,  6),
        glm::ivec3( 4,  6,  7),
        glm::ivec3( 8,  9, 10),
        glm::ivec3( 8, 10, 11),
        glm::ivec3(12, 13, 14),
        glm::ivec3(12, 14, 15),
        //Roof
        glm::ivec3(16, 17, 18),
        glm::ivec3(19, 20, 21),
        glm::ivec3(22, 23, 24),
        glm::ivec3(25, 26, 27),
    };
}