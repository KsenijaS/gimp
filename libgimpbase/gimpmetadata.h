/* LIBGIMPBASE - The GIMP Basic Library
 * Copyright (C) 1995-1997 Peter Mattis and Spencer Kimball
 *
 * gimpmetadata.h
 * Copyright (C) 2013 Hartmut Kuhse <hartmutkuhse@src.gnome.org>
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef __GIMP_METADATA_H__
#define __GIMP_METADATA_H__

G_BEGIN_DECLS


typedef enum
{
  GIMP_METADATA_SAVE_EXIF      = 1 << 0,
  GIMP_METADATA_SAVE_XMP       = 1 << 1,
  GIMP_METADATA_SAVE_IPTC      = 1 << 2,
  GIMP_METADATA_SAVE_THUMBNAIL = 1 << 3,

  GIMP_METADATA_SAVE_ALL       = (GIMP_METADATA_SAVE_EXIF     |
                                  GIMP_METADATA_SAVE_XMP      |
                                  GIMP_METADATA_SAVE_IPTC     |
                                  GIMP_METADATA_SAVE_THUMBNAIL)
} GimpMetadataSaveFlags;


GimpMetadata * gimp_metadata_new                 (void);

GimpMetadata * gimp_metadata_deserialize         (const gchar   *metadata_xml);
gchar        * gimp_metadata_serialize           (GimpMetadata  *metadata);

GimpMetadata * gimp_metadata_load_from_file      (GFile         *file,
                                                  GError       **error);
gboolean       gimp_metadata_save_to_file        (GimpMetadata  *metadata,
                                                  GFile         *file,
                                                  GError       **error);

gboolean       gimp_metadata_set_from_exif       (GimpMetadata  *metadata,
                                                  const guchar  *exif_data,
                                                  gint           exif_data_length);
gboolean       gimp_metadata_set_from_xmp        (GimpMetadata  *metadata,
                                                  const guchar  *xmp_data,
                                                  gint           xmp_data_length);

void           gimp_metadata_set_pixel_size      (GimpMetadata  *metadata,
                                                  gint           width,
                                                  gint           height);
void           gimp_metadata_set_bits_per_sample (GimpMetadata  *metadata,
                                                  gint           bits_per_sample);

gboolean       gimp_metadata_get_resolution      (GimpMetadata  *metadata,
                                                  gdouble       *xres,
                                                  gdouble       *yres,
                                                  GimpUnit      *unit);
void           gimp_metadata_set_resolution      (GimpMetadata  *metadata,
                                                  gdouble        xres,
                                                  gdouble        yres,
                                                  GimpUnit       unit);

gboolean       gimp_metadata_is_tag_supported    (const gchar   *tag,
                                                  const gchar   *mime_type);


G_END_DECLS

#endif /* __GIMP_METADATA_H__ */