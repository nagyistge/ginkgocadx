/*
 *  Ginkgo CADx Project
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
#include <cmath>
#include <api/iwidgets.h>
#include <api/widgetserializable.h>
#include <widgets/openglhelper.h>

//----------------------------------------------------------------------------------------------------
//region Forward Declarations
namespace GNC
{
namespace GCS
{
namespace Widgets
{

namespace Dialogos
{
class SeleccionTexto;
}

class WTextBox;
struct TextBoxTexture;
}
}
}
//endregion

namespace GNC
{
namespace GCS
{
namespace Widgets
{

namespace Dialogos
{
class SeleccionTexto;
}

class WTextBox;

//====================================================================================================
//= Multipurpose text box wiget
//====================================================================================================
class WTextBox : public GNC::GCS::Widgets::IWidget, public GNC::GCS::Widgets::IWidgetSerializable
{

public:
        typedef enum TNoteMode {
                TNM_Static, //static text edited by user
                TNM_Dynamic //text can not be edited by user
        } TNoteMode;
        typedef GNC::GCS::Vector TVector;
        typedef GNC::GCS::Matriz TMatriz;

        WTextBox(IWidgetsManager* pManager, long vid, TVector posicion, TNoteMode mode, const char* nombre = "", std::string texto = "");

        ~WTextBox();

        //----------------------------------------------------------------------------------------------------
        //region "Serializado y desserializado"
public:
        WTextBox(IWidgetsManager* pManager, long vid, wxXmlNode* nodo);

        wxXmlNode* Serializar(const std::string& nombreMedico);
        void DoEditText(wxWindow* pWindow);
        //endregion

        TVector          m_Posicion;
        TVector          m_PosAntigua;

        TVector          m_Quad[4]; // Quad position in plane coordiantes

        GNC::GCS::Vector m_TamTexto;

        std::string      m_Texto;
        bool             m_Vacio;
        bool			 m_Enabled;
        TNoteMode		 m_mode;


        typedef std::map<void*,TextBoxTexture*> TMapaRecursos;
        TMapaRecursos m_mapaRecursos;
        TextBoxTexture* GetTextura(void* renderer);
        void Invalidar();

        GNC::GCS::Widgets::Dialogos::SeleccionTexto* m_pWidgetSeleccion;

protected:
        bool m_MouseDown;


        //----------------------------------------------------------------------------------------------------
        //region "Colores"
public:

        virtual const std::string& GetTexto() const;
        virtual void SetTexto(const std::string& texto);
        virtual void SetPosition(const TVector& pos);
        virtual void PropagarModificacion();
        virtual void Enable(bool enabled);
        virtual bool Enabled();
        //endregion

        //----------------------------------------------------------------------------------------------------
        //region "Interfaz especifica"
public:

        virtual bool SoportaAutoBorrado() const;

        virtual void OnMouseEvents(GNC::GCS::Events::EventoRaton&);

        virtual void OnKeyEvents(GNC::GCS::Events::EventoTeclado&);

        virtual bool HitTest(float x, float y, const GNC::GCS::Vector& umbral);

        virtual bool HitTest(GNC::GCS::Vector* vertices, int numVertices);

        virtual void Render(GNC::GCS::Contexto3D* c);

        virtual void OffscreenRender(Contexto3D* c);

        virtual void Seleccionar(bool seleccionado);

        virtual void Iluminar(bool iluminado);

        virtual void Ocultar(bool oculto);

        virtual void LiberarRecursos(GNC::GCS::IWidgetsRenderer* pKey);

        //----------------------------------------------------------------------------------------------------
        //region "Helpers"
public:
        virtual void Recalcular(void* renderer);
        //endregion

        //----------------------------------------------------------------------------------------------------
        //region "Menu contextual"
public:
        virtual bool GetMenuContextual(wxMenu* , wxWindow* pParent) ;
        //endregion

        virtual void InsertarPropiedades(TListaMapasPropiedades &listaMapaPropiedades);

};
}
}
}
