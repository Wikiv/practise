
#include "FileDescriptor.h"
#include "EventFax.h"

using namespace UBACIPC;

FileDescriptor::FileDescriptor(int fd)
{
    init();
    descriptor = fd;
}

FileDescriptor::FileDescriptor()
{
    init();
}

void FileDescriptor::init()
{   
    descriptor = -1;
    eventFax = NULL;
    bMarkRemFromEFax = false;
    bRemovedFromEFax = false;
    bDataAvailForRead = false;
}

void FileDescriptor::addOUTEvent()
{
    if ( eventFax != NULL )
        eventFax->addOUTEvent(this);
}

void FileDescriptor::delOUTEvent()
{
    if ( eventFax != NULL )
        eventFax->removeOUTEvent(this);
}

void FileDescriptor::markForRemovalFromEventFax()
{
    this->bMarkRemFromEFax = true;
}

bool FileDescriptor::isMarkedForRemovalFromEventFax()
{
    return this->bMarkRemFromEFax;
}

bool FileDescriptor::isRemFromEFax()
{
    return this->bRemovedFromEFax;
}

void FileDescriptor::setDataAvailForRead(bool flag)
{
    this->bDataAvailForRead = flag;
}

bool FileDescriptor::isDataAvailForRead()
{
    return this->bDataAvailForRead;
}
