#include "logic/include/scene/constructor/figure/canvasvertex.h"

CanvasVertex::CanvasVertex(obj3d::Vertex3D &vertex, Camera &camera) :
    tag_(vertex.getTag()) {
    obj3d::Vector3D projected_vector(camera.getPlane()->projectPoint(*vertex.getPosition()));
    obj3d::Point2D expanded_pt = camera.getBasis()->expandVector(projected_vector).toPoint2D();
    pos_ = std::make_shared<obj3d::Point2D>(expanded_pt);
}

std::shared_ptr<std::string> CanvasVertex::getTag() {
    return tag_;
}

std::shared_ptr<obj3d::Point2D> CanvasVertex::getPosition() {
    return pos_;
}
