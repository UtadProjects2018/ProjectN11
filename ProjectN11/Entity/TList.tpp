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
    InitNodes();
}

template <class T>
TListSystem::TList<T>::~TList()
{
    DeleteNodes();
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
    node = new TNode();
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
        DeleteNodes();
    }
    else if (m_size == 1)
    {
        DeleteNodes();
        m_size --;
    }
    else
    {
        lastNode = lastNode->previousNode;
        m_size --;
    }
    
    if (!lastNode)
    {
        return NULL;
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

template <class T>
void TListSystem::TList<T>::InitNodes()
{
    firstNode = nullptr;
    lastNode  = nullptr;
    selectedNode = nullptr;
    m_size = 0;
}

template <class T>
void TListSystem::TList<T>::DeleteNodes()
{
    firstNode = nullptr;
    lastNode  = nullptr;
    selectedNode = nullptr;
    
    delete firstNode;
    delete lastNode;
    delete selectedNode;
}
