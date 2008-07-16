/*------------------------------------------------------------------------------
* Copyright (C) 2003-2006 Ben van Klinken and the CLucene Team
* 
* Distributable under the terms of either the Apache License (Version 2.0) or 
* the GNU Lesser General Public License, as specified in the COPYING file.
------------------------------------------------------------------------------*/

#ifndef _lucene_search_BooleanScorer2_
#define _lucene_search_BooleanScorer2_

#include "Scorer.h"
//#include "ConjunctionScorer.h"
//#include "DisjunctionSumScorer.h"

CL_NS_DEF(search)
	
	class BooleanScorer2: public Scorer {
	private:
	    class Internal;
		friend class Internal;
	    Internal* internal;
	    
	    class Coordinator;
	    class SingleMatchScorer;
	    class NonMatchingScorer;
	    class ReqOptSumScorer;
	    class ReqExclScorer;
	    class BSConjunctionScorer;
	    class BSDisjunctionSumScorer;
	protected:
		bool score( HitCollector* hc, const int32_t max );
	public:

		BooleanScorer2( Similarity* similarity, int32_t minNrShouldMatch, bool allowDocsOutOfOrder );
		~BooleanScorer2();
		
		void add( Scorer* scorer, bool required, bool prohibited );
		void score( HitCollector* hc );
		int32_t doc() const;
		bool next();
		float_t score();
		bool skipTo( int32_t target );
		void explain( int32_t doc, Explanation* ret );
		TCHAR* toString();
	};

CL_NS_END
#endif