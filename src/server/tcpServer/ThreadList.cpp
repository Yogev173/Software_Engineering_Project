#include "ThreadList.h"

void ThreadList::add(pthread_t threadID) {
    m_threadID.push_back(threadID);
}

void ThreadList::remove(pthread_t threadID) {
    m_threadID.erase(std::find(m_threadID.begin(),m_threadID.end(), threadID));
}

std::vector<pthread_t> ThreadList::getThreads() {
    return m_threadID;
}