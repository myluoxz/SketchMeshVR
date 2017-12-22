#ifndef _SurfacePath_H_
#define _SurfacePath_H_
#include <Eigen/Core>
#include "Stroke.h"

//This class  is used for curves that are drawn onto an existing mesh surface, and that need to generate new mesh vertices and edges etc. (whereas the Stroke class simply takes drawn curves as they are)
class PathElement;

class SurfacePath {
public:


	SurfacePath();
	void create_from_stroke(const Stroke& stroke);


private:
	int extend_path(int prev_p, int next_p, int faceID, bool& forward, bool front_facing_only, Eigen::Matrix4f modelview);
	int find_next_edge(std::pair<int, int> strokeEdge, int prev_edge, int polygon, Eigen::Matrix4f modelview);
	bool edges2D_cross(std::pair<Eigen::Vector2d, Eigen::Vector2d> edge1, std::pair<Eigen::Vector2d, Eigen::Vector2d> edge2);
	bool front_facing(int faceID);
	bool is_projected_inside(Eigen::RowVector2d v, int face, Eigen::Matrix4f modelview);
	int cross_prod2D(Eigen::Vector2d vec0, Eigen::Vector2d vec1);
	std::vector<PathElement> path;
};



class PathElement {
public:
	enum ElementType { EDGE, FACE };
	PathElement(int ID_, ElementType type_, Eigen::Vector3d vertex_) :
		ID(ID_),
		type(type_),
		vertex(vertex_){
	};

	Eigen::Vector3d get_vertex() { return vertex; };

private:
	int ID;
	ElementType type;
	Eigen::Vector3d vertex;
};

#endif