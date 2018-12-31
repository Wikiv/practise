#include "UBACData.h"

GainerLoserVolumeResponse::GainerLoserVolumeResponse()
{
}

GainerLoserVolumeResponse::~GainerLoserVolumeResponse()
{
}

void GainerLoserVolumeResponse::toString( string & response )
{
	response.append( "852 <" );
	CSVData *ptr = static_cast<CSVData *>(this);
	ptr->toString( response, '|' );
	response.append( ">" );
}
