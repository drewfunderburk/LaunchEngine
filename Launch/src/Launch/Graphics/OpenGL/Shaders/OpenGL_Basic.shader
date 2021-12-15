#vertex
#version 330 core

layout(location = 0) in vec4 vPosition;

void main()
{
	gl_Position = vPosition;
}

#fragment
#version 330 core

layout(location = 0) out vec4 fColor;

uniform vec4 uColor;

void main()
{
	fColor = uColor;
}