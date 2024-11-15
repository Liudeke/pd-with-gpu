#include <primitive/floor.h>

#include <meshgen/mesh_generator.h>

namespace primitive
{
    bool Floor::collision_handle(pd::SimVector3& pos) const 
    {
		constexpr static pd::SimScalar EPS = 0.01;
        if (pos.y() < center_point.y() + EPS)
        {
            pos.y() = center_point.y() + EPS;
			return true;
        }
		return false;
    }

    void Floor::generate_visualized_model(Eigen::MatrixXd& V, Eigen::MatrixXi& F) const
    {
		Eigen::MatrixXd uv;
		auto ret = meshgen::generate_plane(41, 41, 1, 1, uv);
		V = ret.first, F = ret.second;
    }

    pd::SimVector3 Floor::center() const 
	{
		return center_point;
	}
	
	void Floor::set_center(pd::SimVector3 center)
	{
		center_point.y() = center.y();
	}
}