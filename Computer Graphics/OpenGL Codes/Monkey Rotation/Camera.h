#ifndef CAMERA_H_INCLUDED
#define  CAMERA_H_INCLUDED

#include<glm/glm.hpp>
#include<glm/gtx/transform.hpp>

class Camera
{
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar) {
		// zNear is the closest distance we can see
		// zFar is the farthest distance we can see
		m_perspective = glm::perspective(fov ,aspect ,zNear , zFar );
		m_position = pos;
		m_forward = glm::vec3(0,0,1);         // forward direction
		m_up = glm::vec3(0, 1, 0);            // upward direction


	}


	inline glm::mat4 GetViewProjection() const
	{
		//glm::lookAt(m_position, m_position + m_forward, m_up) ;
		
		return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);                               
	}


protected:

private:
	glm::mat4 m_perspective;
	glm::vec3 m_position;
	glm::vec3 m_forward;
	glm::vec3 m_up;
};


#endif //  CAMERA_H_INCLUDED
