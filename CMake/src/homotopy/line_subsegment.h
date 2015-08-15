#ifndef LINE_SUBSEGMENT_H
#define LINE_SUBSEGMENT_H

#include <vector>
#include "world_datatype.h"

class Obstacle;
class LineSubSegmentSet;

class IntersectionPoint {
public:
    Point2D m_point;
    double  m_dist_to_bk;

    bool operator<(const  IntersectionPoint& other) const {
        return ( m_dist_to_bk < other.m_dist_to_bk );
    }
};

class LineSubSegment {

public:
    LineSubSegment( Point2D& pos_a, Point2D& pos_b, LineSubSegmentSet* p_subseg_set, unsigned int index, bool is_connected_to_central_point = false );
    ~LineSubSegment();

    Segment2D m_subseg;
    LineSubSegmentSet* _p_subseg_set;
    bool m_is_connected_to_central_point;
protected:
    unsigned int _index;

};

typedef enum {
    LINE_TYPE_UNKNOWN,
    LINE_TYPE_ALPHA,
    LINE_TYPE_BETA,
    NUM_LINE_TYPE
} line_subsegment_set_type_t;

class LineSubSegmentSet {

public:
    LineSubSegmentSet( Point2D& pos_a, Point2D& pos_b, unsigned int type, Direction2D direction, Obstacle* p_obstacle );
    ~LineSubSegmentSet();

    bool load( std::vector<IntersectionPoint>& intersections );

    bool operator<(const  LineSubSegmentSet& other) const {
        return ( m_direction < other.m_direction );
    }

    static std::string type_to_std_string ( const unsigned int& type );
    static unsigned int type_from_std_string ( const std::string& type_str );

    Obstacle* get_obstacle() { return _p_obstacle; }

    Segment2D    m_seg;
    Direction2D  m_direction;
    unsigned int m_type;
    std::vector< LineSubSegment* > m_subsegs;
protected:
    Obstacle*    _p_obstacle;
};

#endif // LINE_SUBSEGMENT_H
