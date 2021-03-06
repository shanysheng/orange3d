/*
 * Copyright 2017 sheng chongshan. All rights reserved.
 * email: shany.sheng@qq.com
 * License: https://github.com/shanysheng/RenderPipeline/blob/master/LICENSE
 */



#ifndef PIPELINE_IRENDERMODULE_H_GUARD
#define PIPELINE_IRENDERMODULE_H_GUARD

#include "SGNode.h"

namespace pipeline{
    
    class CCamera;
    class CRenderQueueElement;
    class IRenderingAttribute;
    class CFrameInfo;
    class CRenderQueueElement;
    class IGPUResource;
    
    class IRenderModule
    {
    public:
        virtual ~IRenderModule(){};
        virtual IRenderModule * Clone() const = 0;
        
        virtual IRenderingAttribute * CreateAttribute( SGNode * pFeature ) = 0;
        virtual IRenderingAttribute * DeleteAttribute( SGNode * pFeature ) = 0;
        virtual void AfterFreeGPUResources(CFrameInfo*pFI, SGNode * pFeature, IRenderingAttribute * pAttrib ){};
        
        
        virtual void	ApplyForGPUResources(const CFrameInfo*, const CCamera *, const CRenderQueueElement *,
                                             IRenderingAttribute * pAttrib, std::vector<SGNode*>& GPUResourceApplicants) = 0;
        
        virtual	bool  PrepareResources(const CFrameInfo*, const CCamera *, const CRenderQueueElement *,
                                       IRenderingAttribute * pAttrib, const  std::vector<IGPUResource*>& GPUResources ) =0;
        
        
        virtual void Draw( CFrameInfo*pFI, CCamera * pCamera, CRenderQueueElement * pElement, IRenderingAttribute * pAttrib ) = 0;
    };
}

#endif
