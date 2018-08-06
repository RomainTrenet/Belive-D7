(function($) {
	Drupal.behaviors.multiple_select = {
		attach: function (context, settings) {
      $('select.multiple-select').multipleSelect({
        width: '100%',
        filter: true,
        multiple: false,
				placeholder: Drupal.t('Select'),
        selectAll: true,
        selectAllText: Drupal.t('Select all'),
        allSelected: Drupal.t('All selected'),
			});
		}
	};
})(jQuery);
