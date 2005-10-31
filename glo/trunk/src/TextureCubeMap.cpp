// GLE - Copyright (C) 2005, Nicolas Papier.
// Distributed under the terms of the GNU Library General Public License (LGPL)
// as published by the Free Software Foundation.
// Author Nicolas Papier

#include "glo/TextureCubeMap.hpp"



namespace glo
{



TextureCubeMap::TextureCubeMap() : 
	Texture(GL_TEXTURE_CUBE_MAP_ARB)
{
}



void TextureCubeMap::getSize( int32& width, int32& height, int32& depth ) const
{
	assert( false );
}


} // namespace glo
