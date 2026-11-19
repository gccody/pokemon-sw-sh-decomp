/*
 * The modules YEBIS's FreeType registers (lib/freetype/README.md). Its
 * FT_Init_FreeType (0x710050c880) adds these seven, in this order: the
 * default ftmodule.h's order, without the modules the executable doesn't
 * have. This directory is searched before lib/freetype/include, the way
 * docs/CUSTOMIZE describes, so the upstream file stays as it is.
 */

FT_USE_MODULE( FT_Driver_ClassRec, tt_driver_class )
FT_USE_MODULE( FT_Module_Class, psnames_module_class )
FT_USE_MODULE( FT_Module_Class, pshinter_module_class )
FT_USE_MODULE( FT_Module_Class, sfnt_module_class )
FT_USE_MODULE( FT_Renderer_Class, ft_smooth_renderer_class )
FT_USE_MODULE( FT_Renderer_Class, ft_smooth_lcd_renderer_class )
FT_USE_MODULE( FT_Renderer_Class, ft_smooth_lcdv_renderer_class )

/* EOF */
