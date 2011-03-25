/*
 * THIS CLASS IS NOT FINISHED!!!!!!!!!!
 * THIS CLASS IS NOT FINISHED!!!!!!!!!!
 * THIS CLASS IS NOT FINISHED!!!!!!!!!!
 * THIS CLASS IS NOT FINISHED!!!!!!!!!!
 *
 * Visualization.h
 *
 *      Author: Joel
 *
 *  	VISUALIZATION
 *  	This class contains the reference to a Model and the information
 *  	required to generate a visualization.
 *  	This class is parallel to a visualization window.
 *  	Since a single model can be opened in different visualizations
 *  	the class should have a reference to the concrete model and
 *  	have their own specification details.
 *  	This may include but is not restricted to:
 *  		- camera(zoom, position, etc)
 *  		- color scale
 *
 *		Last update: 11:13 am / 25 / March / 2011
 */

#ifndef VISUALIZATION_H_
#define VISUALIZATION_H_

class Visualization
{
	public:
		Visualization();
		virtual ~Visualization();

		//TO-DO
		//Method to combine the Model and the
		//visualization data and generate the image
		void generate_visualization();
};

#endif /* VISUALIZATION_H_ */
