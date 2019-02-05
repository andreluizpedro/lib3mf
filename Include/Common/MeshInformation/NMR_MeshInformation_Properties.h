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

NMR_MeshInformation_Properties.h defines the Property Information Class.

--*/

#ifndef __NMR_MESHINFORMATION_PROPERTIES
#define __NMR_MESHINFORMATION_PROPERTIES

#include "Common/MeshInformation/NMR_MeshInformation.h"
#include <list>
#include <map>

namespace NMR {

	class CMeshInformation_PropertyIndexMapping {
	private:
		nfUint32 m_nDefaultResourceID;
		nfUint32 m_nDefaultResourceIndex;

		std::map<std::pair <nfUint32, nfUint32>, nfUint32> m_IDMap;
	public:
		CMeshInformation_PropertyIndexMapping();

		nfUint32 mapPropertyIDToIndex(nfUint32 nResourceID, nfUint32 nPropertyID, nfUint32 nDefaultPropertyID);
		
		nfUint32 getDefaultResourceID ();
		nfUint32 getDefaultResourceIndex ();

		nfUint32 registerPropertyID (nfUint32 nResourceID, nfUint32 nPropertyID, nfUint32 nResourceIndex);

	};

	typedef std::shared_ptr <CMeshInformation_PropertyIndexMapping> PMeshInformation_PropertyIndexMapping;


	class CMeshInformation_Properties : public CMeshInformation {
	protected:
	public:
		CMeshInformation_Properties();
		CMeshInformation_Properties(nfUint32 nCurrentFaceCount);

		virtual void invalidateFace(_In_ MESHINFORMATIONFACEDATA * pData);

		virtual eMeshInformationType getType();
		virtual void cloneFaceInfosFrom(_In_ nfUint32 nFaceIndex, _In_ CMeshInformation * pOtherInformation, _In_ nfUint32 nOtherFaceIndex);
		virtual PMeshInformation cloneInstance(_In_ nfUint32 nCurrentFaceCount);
		virtual void permuteNodeInformation(_In_ nfUint32 nFaceIndex, _In_ nfUint32 nNodeIndex1, _In_ nfUint32 nNodeIndex2, _In_ nfUint32 nNodeIndex3);
		virtual nfUint32 getBackupSize();
		virtual void mergeInformationFrom(_In_ CMeshInformation * pInformation);
		virtual nfBool faceHasData(_In_ nfUint32 nFaceIndex);


	};

	typedef std::shared_ptr <CMeshInformation_Properties> PMeshInformation_Properties;

}

#endif // __NMR_MESHINFORMATION_PROPERTIES

