#include "buffer.h"


    Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount)
            : m_ComponentCount(componentCount)
    {
        //Generate our Buffer
        glGenBuffers(1, &m_BufferID);
        //Bind it so we can put data into it
        glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
        glBufferData(m_BufferID, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
        //Unbind the buffer we just created
        glBindBuffer(GL_ARRAY_BUFFER,0);


    }

    void Buffer::bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER,m_BufferID);
    }

    void Buffer::unBind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }
