/*
 * This file is part of Ginkgo CADx
 *
 * Copyright (c) 2015-2016 Gert Wollny
 * Copyright (c) 2008-2014 MetaEmotion S.L. All rights reserved.
 *
 * Ginkgo CADx is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser Public License
 * along with Ginkgo CADx; if not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once
#include "enabled_tools.h"
#if defined(ENABLE_METRICGRIDTOOL)
#ifndef METRICGRIDTOOL_H
#define METRICGRIDTOOL_H
#include <export/tools/imetricgridtool.h>

#include <api/api.h>

#include <map>

namespace GNC
{
class EXTAPI MetricGridTool : public GNC::GCS::IMetricGridTool
{

public:
        virtual GNC::GCS::ITool* NewTool();
        MetricGridTool();
        ~MetricGridTool();

        virtual bool ExecuteAction();
        virtual void AppendToolIn(wxEvtHandler* pParent, wxMenu* pMenu);
        bool IsVisible();
        void ToggleGrid();

        void SetScaleX(double escala);
        void SetScaleY(double escala);

        double GetScaleX();
        double GetScaleY();
protected:
};
}
#endif
#endif
