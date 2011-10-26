//==========================================================================
//                                                                          
// File: ElementarySurface.C                                                 
//                                                                          
// Created: Thu Sep  4 16:49:54 2008                                         
//                                                                          
// Author: Jan B. Thomassen <jbt@sintef.no>
//                                                                          
// Revision: $Id: ElementarySurface.C,v 1.3 2008-12-10 14:52:10 vsk Exp $
//                                                                          
// Description:
//                                                                          
//==========================================================================


#include "GoTools/geometry/ElementarySurface.h"
#include "GoTools/geometry/SplineSurface.h"


namespace Go
{


// Destructor
//===========================================================================
ElementarySurface::~ElementarySurface()
//===========================================================================
{
}


//===========================================================================
RectDomain ElementarySurface::containingDomain() const
//===========================================================================
{
    RectDomain dom = dynamic_cast<const RectDomain&>(parameterDomain());
    return dom;
}


//===========================================================================
bool ElementarySurface::inDomain(double u, double v) const 
//===========================================================================
{
    Array<double, 2> pnt(u, v);
    double eps = 1.0e-8;  // A small number
    return parameterDomain().isInDomain(pnt, eps);
}

//===========================================================================
Point ElementarySurface::closestInDomain(double u, double v) const 
//===========================================================================
{
    Array<double, 2> pnt(u, v);
    Array<double, 2> close(0.0, 0.0);
    double eps = 1.0e-8;  // A small number
    parameterDomain().closestInDomain(pnt, close, eps);
    return Point(close.x(), close.y());
}

//===========================================================================
double ElementarySurface::area(double tol) const
//===========================================================================
{
    return geometrySurface()->area(tol);
}

//===========================================================================
void ElementarySurface::getCornerPoints(std::vector<std::pair<Point,Point> >& corners) const
//===========================================================================
{
  // VSK 0910. Maybe not the best solution in the long run
  geometrySurface()->getCornerPoints(corners);
}

//===========================================================================
bool ElementarySurface::isBounded() const
//===========================================================================
{
    // Assume unbounded by default
    return false;
}

} // namespace Go