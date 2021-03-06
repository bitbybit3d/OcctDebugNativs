#include <math_Vector.hxx>
#include <math_Matrix.hxx>

#include <gp_Circ2d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Pln.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <Geom2d_Circle.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom2dAPI_PointsToBSpline.hxx>
#include <GeomAPI_PointsToBSplineSurface.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <GCPnts_UniformAbscissa.hxx>
#include <TColgp_SequenceOfPnt2d.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TCollection_ExtendedString.hxx>

#include <TopoDS_Shape.hxx>
#include <BrepPrimAPI_MakeBox.hxx>
#include <BRepTools.hxx>
#include <TopExp.hxx>

#include <Geom_CartesianPoint.hxx>
#include <Geom_Line.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Ellipse.hxx>
#include <Geom_Plane.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <Geom_ConicalSurface.hxx>

static void test_gp_tkgeom_visulizers()
{
    gp_XY  coord2d;
    gp_XYZ coord3d;
    gp_Pnt2d pnt2d;
    gp_Pnt   pnt3d;
    gp_Ax1   axis;
    gp_Ax2   csys;
    gp_Ax3 theAxe(gp::XOY());

    gp_Mat2d mat2d;
    gp_Mat mat3d;
    gp_Trsf2d trsf2d;
    gp_Trsf trsf3d;

    gp_Lin2d lin2d;
    gp_Circ2d cir2d;
    gp_Ax22d ax22d;
    gp_Elips2d ell2d;

    gp_Lin lin;
    gp_Circ cir(gp_Ax2(), 5.);
    gp_Elips ell3d;

    gp_Pln PL(theAxe);

    Handle(Geom_Point) hPnt = new Geom_CartesianPoint(1, 2, 3);
    Handle(Geom_Line) hLin = new Geom_Line(gp_Pnt(1, 2, 3), gp_Dir(0, 0, 1));
    Handle(Geom_Circle) hCir = new Geom_Circle(csys, 5);

    Handle(Geom_Plane) hPln = new Geom_Plane(theAxe);
    Handle(Geom_CylindricalSurface) hCyl = new Geom_CylindricalSurface(theAxe, 5);

    TCollection_AsciiString str("abcd");

    TCollection_ExtendedString wstr(L"abcd 汉字");

    std::cout << hPln->get_type_name() << std::endl;
}

static void test_ncollection_array_visulizer()
{
    TColgp_Array1OfPnt emptyArray;

    TColgp_Array1OfPnt2d array1(1, 5); // sizing array                    
    array1.SetValue(1, gp_Pnt2d(0, 0));
    array1.SetValue(2, gp_Pnt2d(1, 2));
    array1.SetValue(3, gp_Pnt2d(2, 3));
    array1.SetValue(4, gp_Pnt2d(4, 3));
    array1.SetValue(5, gp_Pnt2d(5, 5));
    Handle(Geom2d_BSplineCurve) SPL1 =
        Geom2dAPI_PointsToBSpline(array1);

    TColgp_Array2OfPnt array3(1, 4, 1, 5);
    array3.SetValue(1, 1, gp_Pnt(-4, -4, 5));
    array3.SetValue(1, 2, gp_Pnt(-4, -2, 5));
    array3.SetValue(1, 3, gp_Pnt(-4, 0, 4));
    array3.SetValue(1, 4, gp_Pnt(-4, 2, 5));
    array3.SetValue(1, 5, gp_Pnt(-4, 4, 5));

    array3.SetValue(2, 1, gp_Pnt(-2, -4, 4));
    array3.SetValue(2, 2, gp_Pnt(-2, -2, 4));
    array3.SetValue(2, 3, gp_Pnt(-2, 0, 4));
    array3.SetValue(2, 4, gp_Pnt(-2, 2, 4));
    array3.SetValue(2, 5, gp_Pnt(-2, 5, 4));

    array3.SetValue(3, 1, gp_Pnt(0, -4, 3.5));
    array3.SetValue(3, 2, gp_Pnt(0, -2, 3.5));
    array3.SetValue(3, 3, gp_Pnt(0, 0, 3.5));
    array3.SetValue(3, 4, gp_Pnt(0, 2, 3.5));
    array3.SetValue(3, 5, gp_Pnt(0, 5, 3.5));

    array3.SetValue(4, 1, gp_Pnt(2, -4, 4));
    array3.SetValue(4, 2, gp_Pnt(2, -2, 4));
    array3.SetValue(4, 3, gp_Pnt(2, 0, 3.5));
    array3.SetValue(4, 4, gp_Pnt(2, 2, 5));
    array3.SetValue(4, 5, gp_Pnt(2, 5, 4));

//     array3.SetValue(5, 1, gp_Pnt(4, -4, 5));
//     array3.SetValue(5, 2, gp_Pnt(4, -2, 5));
//     array3.SetValue(5, 3, gp_Pnt(4, 0, 5));
//     array3.SetValue(5, 4, gp_Pnt(4, 2, 6));
//     array3.SetValue(5, 5, gp_Pnt(4, 5, 5));

    Handle(Geom_BSplineSurface) aSurf2 =
        GeomAPI_PointsToBSplineSurface(array3).Surface();
}

static void test_handle_seqence_visulizer()
{
    gp_Pnt2d P;
    Standard_Real radius = 5;
    Handle(Geom2d_Circle) C =
        new Geom2d_Circle(gp::OX2d(), radius);
    Geom2dAdaptor_Curve GAC(C);
    Standard_Real abscissa = 3;
    GCPnts_UniformAbscissa UA(GAC, abscissa);
    TColgp_SequenceOfPnt2d aSequence;
    if (UA.IsDone())
    {
        Standard_Real N = UA.NbPoints();
        Standard_Integer count = 1;
        for (; count <= N; count++)
        {
            C->D0(UA.Parameter(count), P);
            //Standard_Real Parameter = UA.Parameter(count);
            // append P in a Sequence
            aSequence.Append(P);
        }
    }
    Standard_Real Abscissa = UA.Abscissa();

    TColStd_ListOfInteger li;

    li.Append(5);
    li.Append(4);
    li.Append(3);
    std::cout << li.Extent() << std::endl;
}

static void test_prim_box()
{
    TopoDS_Shape B1 = BRepPrimAPI_MakeBox(100, 80, 60).Shape();
    TopTools_IndexedMapOfShape theFaces;

    TopExp::MapShapes(B1, TopAbs_FACE, theFaces);
    theFaces.Statistics(std::cout);

    BRepTools::Dump(B1, std::cout);
    std::cout << "BRepTools::Dump end..." << std::endl;
}

int main(int argc, char* argv[])
{
    math_Vector Vec(1, 5);

    Vec(1) = 1;
    Vec(2) = 2;
    Vec(3) = 3;
    Vec(4) = 4;
    Vec(5) = 5;

    math_Matrix mat(1, 2, 1, 3);

    mat(1, 1) = 1;
    mat(1, 2) = 2;
    mat(1, 3) = 3;
    mat(2, 1) = 4;
    mat(2, 2) = 5;
    mat(2, 3) = 6;

    test_gp_tkgeom_visulizers();

    test_ncollection_array_visulizer();

    test_handle_seqence_visulizer();

    test_prim_box();
    return 0;
}
