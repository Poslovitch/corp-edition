if (!hasInterface) exitWith {};

private _logic		= param [0, objNull, [objNull]];
private _objects	= param [1, [], [[]]];

private _actionDText		= _logic getVariable ["ActionText", ""];
private _actionDistance		= _logic getVariable ["ActionDistance", 5];

if (_actionDText == "") then {
  _actionDText = "<t color='#ffffff'><img image='\corp_edition_teleport\icon.paa'/> Téléportation</t>";
};

{
    _x addAction [
        _actionDText,
        { createDialog "CORP_TeleportDialog" },
        nil,
        100,
        true,
        false,
        "",
        format ["(player distance _target) < %1", _actionDistance]
    ];
} forEach _objects;
