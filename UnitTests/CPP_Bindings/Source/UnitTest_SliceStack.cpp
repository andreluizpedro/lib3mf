/*++

Copyright (C) 2018 3MF Consortium

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Abstract:

UnitTest_SliceStack.cpp: Defines Unittests for the SliceStack class

--*/

#include "UnitTest_Utilities.h"
#include "lib3mf.hpp"

namespace Lib3MF
{
	class SliceStack : public ::testing::Test {
	protected:

		static void SetUpTestCase() {
		}

		static void TearDownTestCase() {
		}

		virtual void SetUp() {
			model = CLib3MFWrapper::CreateModel();
			sliceStack = model->AddSliceStack(.0);
			mesh = model->AddMeshObject();

		}
		virtual void TearDown() {
			model.reset();
		}

		PLib3MFModel model;
		PLib3MFSliceStack sliceStack;
		PLib3MFMeshObject mesh;
	};


	TEST_F(SliceStack, HasSetClearSliceStack)
	{
		ASSERT_FALSE(mesh->HasSliceStack());

		mesh->AssignSliceStack(sliceStack.get());
		ASSERT_TRUE(mesh->HasSliceStack());

		auto copySliceStack = mesh->GetSliceStack();
		ASSERT_EQ(copySliceStack->GetResourceID(), sliceStack->GetResourceID());

		mesh->ClearSliceStack();
		ASSERT_FALSE(mesh->HasSliceStack());
	}

	TEST_F(SliceStack, HandleSlices)
	{
		ASSERT_EQ(sliceStack->GetSliceCount(), 0);

		auto slice = sliceStack->AddSlice(0.0);
		ASSERT_EQ(sliceStack->GetSliceCount(), 1);
	}

}
