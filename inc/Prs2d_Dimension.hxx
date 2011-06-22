// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Prs2d_Dimension_HeaderFile
#define _Prs2d_Dimension_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Prs2d_Dimension_HeaderFile
#include <Handle_Prs2d_Dimension.hxx>
#endif

#ifndef _TCollection_ExtendedString_HeaderFile
#include <TCollection_ExtendedString.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _TShort_Array1OfShortReal_HeaderFile
#include <TShort_Array1OfShortReal.hxx>
#endif
#ifndef _Prs2d_TypeOfArrow_HeaderFile
#include <Prs2d_TypeOfArrow.hxx>
#endif
#ifndef _Prs2d_ArrowSide_HeaderFile
#include <Prs2d_ArrowSide.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Graphic2d_Line_HeaderFile
#include <Graphic2d_Line.hxx>
#endif
#ifndef _Handle_Graphic2d_GraphicObject_HeaderFile
#include <Handle_Graphic2d_GraphicObject.hxx>
#endif
#ifndef _Handle_TColgp_HArray1OfPnt2d_HeaderFile
#include <Handle_TColgp_HArray1OfPnt2d.hxx>
#endif
class Graphic2d_CircleDefinitionError;
class Graphic2d_GraphicObject;
class TCollection_ExtendedString;
class TColgp_HArray1OfPnt2d;


//! Groups all dimensions <br>
class Prs2d_Dimension : public Graphic2d_Line {

public:

  //! Sets the text to this dimension <br>
        void SetText(const TCollection_ExtendedString& aText) ;
  //! Sets the scale of text to this dimension <br>
        void SetTextScale(const Standard_Real aTS) ;
  //! Sets the index of the font of this text to this dimension <br>
        void SetTextFont(const Standard_Integer aTF) ;
  //! Sets the index of the font of the symbol to this dimension <br>
        void SetFontOfSymb(const Standard_Integer aFS) ;
  //! Sets the type of arrows to this dimension <br>
        void SetArrowType(const Prs2d_TypeOfArrow anArrT) ;
  //! Sets the number of arrows to this dimension <br>
        void SetArrowSides(const Prs2d_ArrowSide anArrS) ;
  //! Sets the flag for drawing additional symbol <br>
        void DrawSymbol(const Standard_Boolean isDraw) ;
  //! Sets the ASCII code of the symbol <br>
        void SetSymbolCode(const Standard_Integer aCode) ;
  //! Sets the CalcTxtPos(Standard_True) <br>
//!                   myAbsX=Xp <br>
//! 	                 myAbsY=Yp <br>
        void SetTextAbsPos(const Standard_Real Xp,const Standard_Real Yp) ;
  //! Sets the CalcTxtPos(Standard_True) <br>
//!                   myAbsAngle=Ap <br>
        void SetTextAbsAngle(const Standard_Real Ap) ;
  //! Sets the CalcTxtPos(Standard_False) <br>
//!	                 myAbsX=Xp <br>
//! 	                 myAbsY=Yp <br>
        void SetTextRelPos(const Standard_Real Xp,const Standard_Real Yp) ;
  //! Sets the CalcTxtPos(Standard_False) <br>
//!	                 myAbsAngle=Ap <br>
        void SetTextRelAngle(const Standard_Real Ap) ;
  //! Returns text of this dimension <br>
        TCollection_ExtendedString Text() const;
  //! Returns X - coordinat of text in absolute axis <br>
//! add by enk Wed Dec 11 10:34 2002 <br>
        Standard_Real TextAbsX() const;
  //! Returns Y - coordinat of text in absolute axis <br>
//! add by enk Wed Dec 11 10:34 2002 <br>
        Standard_Real TextAbsY() const;
  //! Returns angle of text in absolute axis <br>
//! add by enk Wed Dec 11 10:34 2002 <br>
        Standard_Real TextAbsAngle() const;
  //! Returns the horizontal position of text <br>
        Standard_Real TextRelH() const;
  //! Returns the vertical position of text <br>
        Standard_Real TextRelV() const;
  //! Returns the angle of text <br>
        Standard_Real TextRelAngle() const;
  //! Returns the scale of text of this dimension <br>
        Standard_Real TextScale() const;
  //! Returns the index of the font of this text of this dimension <br>
        Standard_Integer TextFont() const;
  //! Returns the index of the font of the symbol of this dimension <br>
        Standard_Integer FontOfSymb() const;
  //! Indicates the type of arrows of this dimension <br>
        Prs2d_TypeOfArrow ArrowType() const;
  //! Indicates the number of arrows of this dimension <br>
        Prs2d_ArrowSide ArrowSides() const;
  //! Indicates the angle of arrow of this dimension <br>
        Standard_Real ArrowAngle() const;
  //! Indicates the length of arrow of this dimension <br>
        Standard_Real ArrowLength() const;
  //! Return true if arrows are reversed, false - in otherwise <br>
        Standard_Boolean ArrowIsReversed() const;
  //! Return true if symbol is drawn, false - in otherwise <br>
        Standard_Boolean IsDrawSymbol() const;
  //! Return ASCII code of the symbol <br> 
  // @todo Should really be Standard_Character
        Standard_Integer SymbolCode() const;
  
  Standard_EXPORT    const Handle_TColgp_HArray1OfPnt2d ArrayOfFirstArrowPnt() const;
  
  Standard_EXPORT    const Handle_TColgp_HArray1OfPnt2d ArrayOfSecondArrowPnt() const;




  DEFINE_STANDARD_RTTI(Prs2d_Dimension)

protected:

  //! creates a dimension <br>
  Standard_EXPORT   Prs2d_Dimension(const Handle(Graphic2d_GraphicObject)& aGO,const TCollection_ExtendedString& aText,const Standard_Real aTxtScale,const Standard_Real anArrAngle,const Standard_Real anArrLength,const Prs2d_TypeOfArrow anArrType,const Prs2d_ArrowSide anArrow,const Standard_Boolean IsRevArrow);
  
  Standard_EXPORT   virtual  void CalcTxtPos(const Standard_Boolean theFromAbs = Standard_False)  = 0;

TCollection_ExtendedString myText;
Standard_Real myTextScale;
Standard_Real myTextPosH;
Standard_Real myTextPosV;
Standard_Real myTextAngle;
Standard_Real myAbsX;
Standard_Real myAbsY;
Standard_Real myAbsAngle;
Standard_Integer myTextFont;
Standard_Integer mySymbFont;
TShort_Array1OfShortReal myXVert1;
TShort_Array1OfShortReal myYVert1;
TShort_Array1OfShortReal myXVert2;
TShort_Array1OfShortReal myYVert2;
Prs2d_TypeOfArrow myArrType;
Prs2d_ArrowSide myArrow;
Standard_Real myArrowAng;
Standard_Real myArrowLen;
Standard_Boolean myIsRevArr;
Standard_Boolean myIsSymbol;
Standard_Integer mySymbCode;


private: 




};


#include <Prs2d_Dimension.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
