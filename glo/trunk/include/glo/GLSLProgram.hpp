// GLE - Copyright (C) 2005, 2007, 2008, 2012, 2013, Nicolas Papier, Alexandre Di Pino.
// Distributed under the terms of the GNU Library General Public License (LGPL)
// as published by the Free Software Foundation.
// Author Nicolas Papier
// Author Alexandre Di Pino

#ifndef _GLO_GLSLPROGRAM_HPP
#define _GLO_GLSLPROGRAM_HPP

#include <vector>
#include <string>
#include "glo/IResource.hpp"



namespace glo
{

/**
 * @brief Shader compilation, linking and validation.
 *
 * @todo method to enable/disable all outputs to cerr
 */
struct GLO_API GLSLProgram : public IResource
{
	/**
	 * @brief Enumeration of the different type of shader
	 */
	enum ShaderType
	{
		VERTEX = 0,
		TESSELLATION_CONTROL,
		TESSELLATION_EVALUATION,
		GEOMETRY,
		FRAGMENT,
		PROGRAM,		///< not a real shader type (used by ShadersEditor of vgSDK)
		MAX_SHADER_INDEX
	};

	static const GLenum convertShaderType2GLEnum( const ShaderType shaderType );

	static const std::string& convertShaderType2String( const ShaderType shaderType );

	/**
	 * @name Constructor and destructor
	 */
	//@{

	/**
	 * @brief Default constructor
	 * 
	 * @param initialized	true to create a program object, false to don't do that.
	 */
	GLSLProgram( bool initialized = true );

	/**
	 * @brief Destructor
	 */
	~GLSLProgram();

	/**
	 * @brief Releases OpenGL resource
	 */
	void release();
	//@}


	/**
	 * @brief Adds a new shader to the program
	 * 
	 * @todo doc
	 */
	const bool addShader( const std::string shaderSource, const ShaderType shaderType, const bool linkProgram = false );
	const bool addShader( const GLcharARB *shaderSource, const ShaderType shaderType, const bool linkProgram = false );

	/**
	 * @brief Links the program
	 *
	 * @pre assert( getProgramObject() != 0 && "Empty glsl program" );
	 */
	const bool link( const bool doValidation = true );

	/**
	 * @brief Validates the program
	 */
	const bool validate();



	/**
	 * @name Use methods
	 */
	//@{

	/**
	 * @brief Installs the program as part of current rendering state.
	 */
	void			use();

	/**
	 * @brief Tests if this program is in use.
	 *
	 * @return true if this program is in use, false if not.
	 */
	const bool		isInUse() const;

	/**
	 * @brief Disables the programmable processors and installs the fixed functionality paths in all programmable stages.
	 */
	static void		useFixedPaths();
	//@}


	/**
	 * @name Shader accessors
	 */
	//@{

	/**
	 * @brief Gets the shader name
	 *
	 * @param shaderType	the type of the needed shader
	 */
	const GLuint getName(const ShaderType shaderType) const;

	/**
	 * @brief Gets the shader code
	 *
	 * @param shaderType	the type of the needed shader code
	 */
	const std::string getShaderCode(const ShaderType shaderType) const;

	/**
	 * @brief Sets the shader code
	 *
	 * @param shaderType	the type of the needed shader
	 * @param code			the shader code
	 */
	void setShaderCode(const ShaderType shaderType, const std::string code);

	/**
	 * @brief Gets the log error
	 *
	 * @param shaderType	the type of the needed shader
	 */
	const std::string getLogError(const ShaderType shaderType) const;

	/**
	 * @brief Sets the shader log error
	 *
	 * @param shaderType	the type of the needed shader
	 * @param error			the shader code
	 */
	void setLogError(const ShaderType shaderType, const std::string error);

	//@}



	/**
	 * @name Program accessors
	 */
	//@{

	/**
	 * @brief Gets if the current link has success
	 */
	const bool getLinkSuccess() const;

	/**
	 * @brief Gets the link log 
	 */
	const std::string getLinkLog() const;

	//@}



	/**
	 * @name Uniform Variables accessors
	 * 
	 * @todo static ?
	 */
	//@{
	void setUniform1i( const std::string & name, const GLint v1 );
	void setUniform2i( const std::string & name, const GLint v1, const GLint v2 );
	void setUniform3i( const std::string & name, const GLint v1, const GLint v2, const GLint v3 );
	void setUniform4i( const std::string & name, const GLint v1, const GLint v2, const GLint v3, const GLint v4 );

	void setUniform1f( const std::string & name, const GLfloat v1 );
	void setUniform2f( const std::string & name, const GLfloat v1, const GLfloat v2 );
	void setUniform3f( const std::string & name, const GLfloat v1, const GLfloat v2, const GLfloat v3 );
	void setUniform4f( const std::string & name, const GLfloat v1, const GLfloat v2, const GLfloat v3, const GLfloat v4 );

// @todo *ui

	void setUniform1iv( const std::string & name, const GLint * value, const GLsizei count = 1 );
	void setUniform2iv( const std::string & name, const GLint * value, const GLsizei count = 1 );
	void setUniform3iv( const std::string & name, const GLint * value, const GLsizei count = 1 );
	void setUniform4iv( const std::string & name, const GLint * value, const GLsizei count = 1 );

	void setUniform1fv( const std::string & name, const GLfloat * value, const GLsizei count = 1 );
	void setUniform2fv( const std::string & name, const GLfloat * value, const GLsizei count = 1 );
	void setUniform3fv( const std::string & name, const GLfloat * value, const GLsizei count = 1 );
	void setUniform4fv( const std::string & name, const GLfloat * value, const GLsizei count = 1 );

// @todo *uiv

	void setUniformMatrix2fv( const std::string & name, const GLfloat * value, const GLboolean transpose = GL_FALSE, const GLsizei count = 1 );
	void setUniformMatrix3fv( const std::string & name, const GLfloat * value, const GLboolean transpose = GL_FALSE, const GLsizei count = 1 );
	void setUniformMatrix4fv( const std::string & name, const GLfloat * value, const GLboolean transpose = GL_FALSE, const GLsizei count = 1 );
	void setUniformMatrix2x3fv( const std::string & name, const GLfloat * value, const GLboolean transpose = GL_FALSE, const GLsizei count = 1 );
	void setUniformMatrix3x2fv( const std::string & name, const GLfloat * value, const GLboolean transpose = GL_FALSE, const GLsizei count = 1 );
	void setUniformMatrix2x4fv( const std::string & name, const GLfloat * value, const GLboolean transpose = GL_FALSE, const GLsizei count = 1 );
	void setUniformMatrix4x2fv( const std::string & name, const GLfloat * value, const GLboolean transpose = GL_FALSE, const GLsizei count = 1 );
	void setUniformMatrix3x4fv( const std::string & name, const GLfloat * value, const GLboolean transpose = GL_FALSE, const GLsizei count = 1 );
	void setUniformMatrix4x3fv( const std::string & name, const GLfloat * value, const GLboolean transpose = GL_FALSE, const GLsizei count = 1 );

// @todo dsa version
	// GL_ARB_separate_shader_objects (OpenGL 4.1): DSA style api
	void setProgramUniform1i( const std::string & name, const GLint v1 );
	//@}



	/**
	 * @name Queries
	 */
	//@{

	struct UniformInformations
	{
		UniformInformations( const int nameMaxLength = 512 ) :
			type( 0 ),
			name( nameMaxLength, 0 ),
			size( 0)
		{}

		GLenum					type;
		std::string				name;
		GLint					size;
		// @todo value ?
	};

	const std::string getActiveUniformsStr() const;
	const std::vector< UniformInformations > getActiveUniforms() const;

	const std::string toString( const GLenum type ) const;
	const std::string toString( const std::vector< UniformInformations >& uniforms ) const;

	//@}



	/**
	 * @brief Load a file in a string
	 */
	static const std::string loadFile( const std::string pathfilename );

	const GLuint getProgramObject() const;


protected:
	/**
	 * @brief Returns the uniform location of the uniform variable
	 * 
	 * @param name	name of the uniform whose location to be queried
	 *
	 * @return The value of -1 will be returned if name does not correspond to an active uniform or if name starts with the reserved prefix "gl_"
	 */
	const GLint getUniformLocation( const std::string & name ) const;



private:
	const std::string getShaderInfoLog( GLuint object );
	const std::string getProgramInfoLog( GLuint object );

	// SHADER INFORMATIONS
	struct ShaderInformations
	{
		ShaderInformations()
		:	// shaderCode
			shaderSaved(0)
			// shaderLog
		{}

		std::string	shaderCode;
		GLuint		shaderSaved;
		std::string	shaderLog;
	};

	std::vector<ShaderInformations> m_shaderInfo;

	// PROGRAM
	GLuint		m_programObject;
	std::string	m_linkLog;
	bool		m_linkSuccess;

	static GLenum		m_GLEnumShaderType[];
	static std::string	m_stringShaderType[];

	static bool		m_firstInstance;
};



} // namespace glo

#endif //#ifndef _GLO_GLSLPROGRAM_HPP
