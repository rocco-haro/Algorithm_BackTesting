/*
 * GraphAttributes.h
 *
 *  Created on: Dec 2, 2016
 *      Author: rocco
 */

#ifndef GRAPHATTRIBUTES_H_
#define GRAPHATTRIBUTES_H_


class GraphAttributes {
public:
	GraphAttributes();

	void setMin(int in);
	void setMax(int in);
	void setInterval(int in);

	int getMin();
	int getMax();
	int getInterval();

private:
	int min;
	int max;
	int interval;
};

#endif /* GRAPHATTRIBUTES_H_ */
