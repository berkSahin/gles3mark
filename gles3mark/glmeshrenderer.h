

#pragma once

#include "glhelper.h"
#include "mesh.h"

class GLMeshRenderer {
    GLuint VBO, EBO, VAO;

    struct VboEntry {
        glm::vec3 pos;          // layout (location=0)
        glm::vec3 normal;       // layout (location=1)
        //glm::vec3 tangent;    
        glm::vec2 texcoord;     // layout (location=2)
    };



public:
     Mesh* mesh;

    void Init(Mesh* mesh) {
        this->mesh = mesh;
        
        // Copy data to graphics card
        glGenBuffers(1, &VBO);      // TODO neni treba ukladat? - staci ulozit jen VAO -- stejna promenna na vsechny docasne buffery
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        GL_CHECK( glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * sizeof(VboEntry), nullptr, GL_STATIC_DRAW) );

        for (size_t i = 0; i < mesh->vertices.size(); ++i) {
            GL_CHECK( glBufferSubData(GL_ARRAY_BUFFER, i * sizeof(VboEntry) + offsetof(VboEntry, pos)     , sizeof(glm::vec3), &mesh->vertices [i]) );
            GL_CHECK( glBufferSubData(GL_ARRAY_BUFFER, i * sizeof(VboEntry) + offsetof(VboEntry, normal)  , sizeof(glm::vec3), &mesh->normals  [i]) );
            GL_CHECK( glBufferSubData(GL_ARRAY_BUFFER, i * sizeof(VboEntry) + offsetof(VboEntry, texcoord), sizeof(glm::vec2), &mesh->texCoords[i]) );
        }
        
        // setup vbo for index buffer
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        GL_CHECK( glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->faces.size()*sizeof(glm::ivec3), &mesh->faces[0].x, GL_STATIC_DRAW) );


        // setup VAO
        // Narozdil od VBO neukladaji data o vrcholech (pozice, normala, ...), ale ukladaji reference na VBO a nastaveni atributu.
        // VAO usnadnuji a urychluji vykreslovani. Pro vykresleni staci aktivovat VAO a ten si pamatuje veskere nastaveni.
        // subsequent calls that change the vertex array state (glBindBuffer, glVertexAttribPointer, glEnableVertexAttribArray, and glDisableVertexAttribArray) will affect the new VAO.
        glGenVertexArrays(1, &VAO);  // TODO VAO + UBO pro kazdy mesh?
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        // setup vertex shader attribute bindings (connecting current <position and tc> buffer to associated 'in' variable in vertex shader)
        GL_CHECK( glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VboEntry), (GLvoid*)offsetof(VboEntry, pos     )) );
        GL_CHECK( glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VboEntry), (GLvoid*)offsetof(VboEntry, normal  )) );
        GL_CHECK( glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VboEntry), (GLvoid*)offsetof(VboEntry, texcoord)) );

        // enable vertex buffers
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);

        // unbind VAO
        glBindVertexArray(0);
    }

    void Render() {
        glBindVertexArray(VAO);
        GL_CHECK( glDrawElements(GL_TRIANGLES, mesh->faces.size() * 3, GL_UNSIGNED_INT, nullptr) );  // sizeof house / sizeof house[0]
        glBindVertexArray(0);
    }

    void Destroy() {
        //glBindVertexArray(0);
        //glBindBuffer(GL_ARRAY_BUFFER, 0);
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
        glDeleteVertexArrays(1, &VAO);
    }
};