#include "xiutanscanner.h"

xiutanscanner::xiutanscanner()
{

}

void xiutanscanner::run()
{

}

void xiutanscanner::stop()
{
    this->stopped=false;
}

void xiutanscanner::getdev(pcap_if_t* current_dev)
{
    this->current_dev=current_dev;
}
