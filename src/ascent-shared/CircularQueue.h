/*
 * Ascent MMORPG Server
 * Copyright (C) 2005-2010 Ascent Team <http://www.ascentemulator.net/>
 *
 * This software is  under the terms of the EULA License
 * All title, including but not limited to copyrights, in and to the AscentNG Software
 * and any copies there of are owned by ZEDCLANS INC. or its suppliers. All title
 * and intellectual property rights in and to the content which may be accessed through
 * use of the AscentNG is the property of the respective content owner and may be protected
 * by applicable copyright or other intellectual property laws and treaties. This EULA grants
 * you no rights to use such content. All rights not expressly granted are reserved by ZEDCLANS INC.
 *
 */

#ifndef __CIRCULARQUEUE_H
#define __CIRCULARQUEUE_H

template<class T, int ELEMENTCOUNT>
class CircularQueue
{
	T m_elements[ELEMENTCOUNT];
	int m_pos;
public:
	CircularQueue() : m_pos(0)
	{
		memset(m_elements, 0, sizeof(T) * ELEMENTCOUNT);
	}
	~CircularQueue() {}

	void push(T& val)
	{
		m_elements[++m_pos] = val;
		if(m_pos >= ELEMENTCOUNT)
			m_pos = 0;
	}

	inline T * get()
	{
		return m_elements;
	}

	/* assumes we're int-based */
    void print()
	{
		printf("Elements of CircularQueue[%u]: ", ELEMENTCOUNT);
		for(int i = 0; i < ELEMENTCOUNT; ++i)
			printf("%u ", (int)m_elements[i]);
		printf("\n");
	}
};

#endif		// _CIRCULARQUEUE_H
