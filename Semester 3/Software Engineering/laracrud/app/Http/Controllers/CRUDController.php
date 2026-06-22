<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\User;

class CRUDController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        return response()->view('crud.index',['User'=> User::orderBy('name', 'asc') ->get(),]);
    }

    /**
     * Show the form for creating a new resource.
     */
    public function create()
    {
        //
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(Request $request)
    {
        //
    }

    /**
     * Display the specified resource.
     */
    public function show(string $id)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(string $id)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, string $id)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(string $id)
    {
        $user=user::findOrFail($id);
        $delete=$user->delete($id);

        if($delete)
        {
            session()->flash('notif.success', 'User successfully deleted');
            return redirect()->route('crud.index');
        }
    }
}
