// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC2d_HeaderFile
#define _Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC2d_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC2d_HeaderFile
#include <Handle_Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC2d.hxx>
#endif

#ifndef _Extrema_POnCurv2d_HeaderFile
#include <Extrema_POnCurv2d.hxx>
#endif
#ifndef _TCollection_SeqNode_HeaderFile
#include <TCollection_SeqNode.hxx>
#endif
#ifndef _TCollection_SeqNodePtr_HeaderFile
#include <TCollection_SeqNodePtr.hxx>
#endif
class Extrema_POnCurv2d;
class Extrema_SeqPCOfPCFOfEPCOfExtPC2d;



class Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC2d : public TCollection_SeqNode {

public:

  
      Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC2d(const Extrema_POnCurv2d& I,const TCollection_SeqNodePtr& n,const TCollection_SeqNodePtr& p);
  
        Extrema_POnCurv2d& Value() const;




  DEFINE_STANDARD_RTTI(Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC2d)

protected:




private: 


Extrema_POnCurv2d myValue;


};

#define SeqItem Extrema_POnCurv2d
#define SeqItem_hxx <Extrema_POnCurv2d.hxx>
#define TCollection_SequenceNode Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC2d
#define TCollection_SequenceNode_hxx <Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC2d.hxx>
#define Handle_TCollection_SequenceNode Handle_Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC2d
#define TCollection_SequenceNode_Type_() Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC2d_Type_()
#define TCollection_Sequence Extrema_SeqPCOfPCFOfEPCOfExtPC2d
#define TCollection_Sequence_hxx <Extrema_SeqPCOfPCFOfEPCOfExtPC2d.hxx>

#include <TCollection_SequenceNode.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif