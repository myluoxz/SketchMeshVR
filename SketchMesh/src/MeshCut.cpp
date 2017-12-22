#include "MeshCut.h"
#include <iostream>
#include <igl/unproject.h>
#include "Mesh.h"
#include "SurfacePath.h"

using namespace std;
using namespace igl;

int MeshCut::prev_vertex_count = -1;
int MeshCut::ID = -1;

void MeshCut::cut(Eigen::MatrixXd &V, Eigen::MatrixXi &F, Eigen::VectorXi &vertex_boundary_markers, Eigen::VectorXi &part_of_original_stroke, Stroke& stroke) {
	if(V.rows() != prev_vertex_count) {
		ID++;
		prev_vertex_count = V.rows();
	}
	Mesh m(V, F, vertex_boundary_markers, part_of_original_stroke, ID);

	SurfacePath surface_path;
	surface_path.create_from_stroke(stroke); //Prepares the drawn stroke (inserts extra points at the edges that it crosses)

	//stroke.prepare_for_cut();
	//cut_main(m);
}

/*void MeshCut::cut_main(Mesh &m) {

}*/