/* 	Header file for gPhoto2

	Author: Scott Fritzinger <scottf@unr.edu>

	This library is covered by the LGPL.
*/


	/* Save/retrieve library or front-end configuration settings. */
	/* ============================================================================== */

	int gp_setting_set (char *id, char *key, char *value);
	int gp_setting_get (char *id, char *key, char *value);
		/*  	id    = unique string for your library/frontend
			key   = the identifier for the setting
			value = the value for the specified key
		*/


	/* Initialize/Quit the gPhoto library */
	/* ============================================================================== */
	int gp_init(int debug);  
		/* 
			debug = enable (1) or disable (0) debugging output 
		*/

	int gp_exit();

	/* Port information */
	/* ============================================================================== */

	/* Retrieve the number of ports available */
	int gp_port_count();

	/* Retrieve port information */
	int gp_port_info(int port_number, CameraPortInfo *info);

	/* Camera information operations */
	/* ============================================================================== */

	/* Retrieve number of cameras */
	int gp_camera_count ();

	/* Retrieve camera name */
	int gp_camera_name (int camera_number, char *camera_name);

	/* Retrieve the camera abilities */
	/* ============================================================================== */
	int gp_camera_abilities 	(int camera_number, CameraAbilities *abilities);
	int gp_camera_abilities_by_name (char *camera_name, CameraAbilities *abilities);

	/* Create a new camera */
	/* ============================================================================== */
	int gp_camera_new 	  (Camera **camera, int camera_number, CameraPortInfo *port);
	int gp_camera_new_by_name (Camera **camera, char *camera_name, CameraPortInfo *port);

	/* Free a camera */
	/* ============================================================================== */
	int gp_camera_free	  (Camera *camera);

	/* Folder operations */
	/* ============================================================================== */
	/* Retrieve the contents of a folder, returns the count */
	int gp_camera_folder_list(Camera *camera, char *folder_path, CameraFolderInfo *list);

	/* Set the current folder */
	int gp_camera_folder_set (Camera *camera, char *folder_path);

	/* File transfer functions */
	/* ============================================================================== */
	/* Retrieve the number of files in the current folder */
	int gp_camera_file_count (Camera *camera);

	/* Download a file or a preview from the camera from the current folder*/
	int gp_camera_file_get 	       (Camera *camera, CameraFile *file, int file_number);
	int gp_camera_file_get_preview (Camera *camera, CameraFile *file, int file_number);

	/* Upload a file to the camera */
	int gp_camera_file_put (Camera *camera, CameraFile *file);

	/* Delete a file from the current folder */
	int gp_camera_file_delete (Camera *camera, int file_number);

	/* Captures the current view. Basically, it takes a picture */
	int gp_camera_capture (Camera *camera, CameraFile *file, CameraCaptureInfo *info);

	/* Miscellaneous functions */
	/* ============================================================================== */

	/* Retrieves camera status (number of pictures, charge, etc...) */
	int gp_camera_summary (Camera *camera, CameraText *summary);

	/* Retrieves usage of the camera library (config settings, problems, etc) */
	int gp_camera_manual (Camera *camera, CameraText *manual);

	/* Retrieves information about the camera library (author, version, etc) */
	int gp_camera_about (Camera *camera, CameraText *about);

	/* Camera configuration operations */
	/* ============================================================================== */

	/* Retrieve and set configuration options for the camera */
	int gp_camera_config_get (Camera *camera, CameraWidget *window);

	/* Send configuration settings to the camera library */
	int gp_camera_config_set (Camera *camera, CameraSetting *setting, int count);

	/* Feedback functions for libraries */
	/* ============================================================================== */

	/* Displays the current status on an operation in the camera */
	int gp_camera_status   (Camera *camera, char *status);

	/* Displays a percentage done in the current operation */
	int gp_camera_progress (Camera *camera, CameraFile *file, float percentage);

	/* Displays a message */
	int gp_camera_message  (Camera *camera, char *message);

	/* Displays a confirmation. returns 1 if answer was "yes", 0 for "no" */
	int gp_camera_confirm  (Camera *camera, char *message);


	/* CameraFile utility functions */
	/* ============================================================================== */

	/* Allocates a new CameraFile */
	CameraFile* gp_file_new ();

	/* Saves/Open image (full path and filename). File data in "file" */
	int gp_file_save (CameraFile *file, char *filename);
	int gp_file_open (CameraFile *file, char *filename);

	/* Frees a CameraFile's components. Same as freeing and creating a new CameraFile */
	int gp_file_clean (CameraFile *file);

	/* Frees a CameraFile from memory */
	int gp_file_free (CameraFile *file);

	/* Add/retrieve a chunk of image data */
	int gp_file_append (CameraFile *file, char *data, int size);
	int gp_file_get_last_chunk (CameraFile *file, char **data, int *size);
	
	/* Widget functions */
	/* ============================================================================== */

	/* Create and free a widget */
	CameraWidget* gp_widget_new  (CameraWidgetType type, char *label);
	int           gp_widget_free (CameraWidget *widget);

	/* Add a widget to a parent (only sections and windows can be parents) */
	int gp_widget_append  (CameraWidget *parent, CameraWidget *child);
	int gp_widget_prepend (CameraWidget *parent, CameraWidget *child);

	/* Return the number of children a parent has */
	int gp_widget_child_count(CameraWidget *parent);

	/* Retrieve a child pointer from a parent */
	CameraWidget* gp_widget_child(CameraWidget *parent, int child_number);

	/* Recursively retrieve a child pointer from a parent */
	CameraWidget* gp_widget_child_by_label(CameraWidget *parent, char *child_label);

	/* Get the type and label of a widget */
	int   gp_widget_type (CameraWidget *widget);
	char *gp_widget_label(CameraWidget *widget);

	/* Set and Get the value of a widget */
	int   gp_widget_value_set (CameraWidget *widget, char *value);
	char *gp_widget_value_get (CameraWidget *widget);

	/* Range functions          */
	/* ------------------------ */

	/* Set/get the value of a range widget */
	int gp_widget_range_set (CameraWidget *range, float low, float high, float increment);
	int gp_widget_range_get (CameraWidget *range, float *low, float *high, float *increment);

	/* Menu and Radio functions */
	/* ------------------------ */

	/* Add a choice to a menu/radio widget */
	int gp_widget_choice_add (CameraWidget *widget, char *choice);

	/* Retrieve the number of choices in a menu/radio widget */
	int gp_widget_choice_count (CameraWidget *widget);

	/* Retrieve a choice from a menu/radio widget */
	char *gp_widget_choice (CameraWidget *widget, int choice_number);

	/* Debugging output         */
	/* ------------------------ */	

	/* Debugging output to stdout. Will dump the widget and all children
	   widgets (and their children, ...) recursively */
	int gp_widget_dump (CameraWidget *widget);
