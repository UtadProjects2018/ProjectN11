//
//  TFile.cpp
//  ProjectN10
//
//  Created by pc-laptop on 11/18/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include "TList.hpp"

template <class T>
TListSystem::TList<T>::TList()
{
    firstNode = nullptr;
    lastNode  = nullptr;
    selectedNode = nullptr;
    m_size = 0;
}

template <class T>
TListSystem::TList<T>::~TList()
{
    delete firstNode;
    delete lastNode;
    delete selectedNode;
    
    firstNode = nullptr;
    lastNode  = nullptr;
    selectedNode = nullptr;
}

template <class T>
unsigned int TListSystem::TList<T>::Size()
{
    return m_size;
}

template <class T>
unsigned int TListSystem::TList<T>::Push(T psz)
{
    TNode *node;
    node = TListSystem::TList<T>::Node();
    node->tlistData = psz;
    
    if(!lastNode)
    {
        firstNode = node;
        lastNode = node;
    }
    else
    {
        lastNode->nextNode = node;
        node->previousNode = lastNode;
        lastNode = node;
    }
    
    if (!selectedNode)
    {
        selectedNode = firstNode;
    }
    
    m_size++;
    
    return m_size;
}

template <class T>
const T TListSystem::TList<T>::First()
{
    selectedNode = firstNode;
    return firstNode->tlistData;
}

template <class T>
const T TListSystem::TList<T>::Next()
{
    if (selectedNode != lastNode)
    {
        selectedNode = selectedNode->nextNode;
    }
    return selectedNode->tlistData;
}

template <class T>
const T TListSystem::TList<T>::Pop()
{
    if (m_size == 0)
    {
        firstNode = nullptr;
        lastNode  = nullptr;
        selectedNode = nullptr;
    }
    else if (m_size == 1)
    {
        firstNode = nullptr;
        lastNode  = nullptr;
        selectedNode = nullptr;
        m_size --;
    }
    else
    {
        lastNode = lastNode->previousNode;
        m_size --;
    }
    
    if (!lastNode)
    {
        return 0;
    }
    else
    {
        return lastNode->tlistData;
    }
}

template <class T>
void TListSystem::TList<T>::Reset()
{
    for (int i = m_size; i > 0; i --)
    {
        Pop();
    }
}
