template <class T>
void GridRenderer::RenderGrid(Grid<T>& grid)
{
  if(m_renderTilesSeparated)
  {
    RenderGridSeparated(grid);
  }
  else
  {
    RenderGridClose(grid);
  }
}

template <class T>
void GridRenderer::RenderGridSeparated(Grid<T>& grid)
{
  Point<int> current;
  Point<int> eventLoc;
  for(int x = 0; x < grid.GetWidth(); x++)
  {
    current.SetX(x * 2);
    for(int y = 0; y < grid.GetHeight(); y++)
    {
      current.SetY(y * 2);
      
      bool renderEW = true;
      
      switch(m_currentEWRenderMode)
      {
      case EVENTWINDOW_RENDER_OFF:
	renderEW = false; break;
      case EVENTWINDOW_RENDER_CURRENT:
	grid.FillLastEventTile(eventLoc);
	renderEW = 
	  current.GetX() == eventLoc.GetX() &&
	  current.GetY() == eventLoc.GetY();
	break;
      case EVENTWINDOW_RENDER_ALL:
	renderEW = true; break;
	break;
      default: break;
      }

      m_tileRenderer->RenderTile(grid.GetTile(x, y),
				 current, renderEW, true);
    }
  }  
}

template <class T>
void GridRenderer::RenderGridClose(Grid<T>& grid)
{
  Point<int> current;
  Point<int> eventLoc;
  for(int x = 0; x < grid.GetWidth(); x++)
  {
    current.SetX(x);
    for(int y = 0; y < grid.GetHeight(); y++)
    {
      current.SetY(y);
      
      bool renderEW = true;
      
      switch(m_currentEWRenderMode)
      {
      case EVENTWINDOW_RENDER_OFF:
	renderEW = false; break;
      case EVENTWINDOW_RENDER_CURRENT:
	grid.FillLastEventTile(eventLoc);
	renderEW = 
	  current.GetX() == eventLoc.GetX() &&
	  current.GetY() == eventLoc.GetY();
	break;
      case EVENTWINDOW_RENDER_ALL:
	renderEW = true; break;
	break;
      default: break;
      }

      m_tileRenderer->RenderTile(grid.GetTile(x, y),
				 current, renderEW, false);
    }
  }
}
